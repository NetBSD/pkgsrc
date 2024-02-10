$NetBSD: patch-src_assistant_qlitehtml_src_container__qpainter.cpp,v 1.1 2024/02/10 11:03:39 wiz Exp $

From 7071977bd53c0e5f0bc5efba55505bb898ce8136 Mon Sep 17 00:00:00 2001
From: Eike Ziller <eike.ziller@qt.io>
Date: Fri, 19 May 2023 14:53:21 +0200
Subject: [PATCH] Update litehtml to v0.9

- lots of smaller changes needed to be adapted to, like std::string
  instead of litehtml::tstring, std::list for child elements, and other
  mostly mechanical changes
- element::is_visible vanished, and we don't get to the render items, so
  replaced that with our own version. render_item::is_visible would also
  take m_skip into account, so this might be wrong for some elements.
  (only relevant for the search index)
- element::get_element_by_point was removed, replace by own depth-first
  iteration deepest_child_at_point. That takes a lot less properties
  into consideration compared to get_element_by_point, like z-order, no
  fixed position elements, etc

Task-number: QTCREATORBUG-29169
Task-number: QTBUG-118990
Fixes: QTBUG-121861
Change-Id: I7264a8407f123f44ba47e47cecc57fbf31a85a3d
Reviewed-by: Jarek Kobus <jaroslaw.kobus@qt.io>
Reviewed-by: Kai Köhne <kai.koehne@qt.io>
---

--- src/assistant/qlitehtml/src/container_qpainter.cpp.orig	2023-11-20 11:56:10.000000000 +0000
+++ src/assistant/qlitehtml/src/container_qpainter.cpp
@@ -48,9 +48,16 @@ static QRect toQRect(litehtml::position 
     return {position.x, position.y, position.width, position.height};
 }
 
-static litehtml::elements_vector path(const litehtml::element::ptr &element)
+static bool isVisible(const litehtml::element::ptr &element)
 {
-    litehtml::elements_vector result;
+    // TODO render_item::is_visible() would also take m_skip into account, so this might be wrong
+    return element->css().get_display() != litehtml::display_none
+           && element->css().get_visibility() == litehtml::visibility_visible;
+}
+
+static litehtml::elements_list path(const litehtml::element::ptr &element)
+{
+    litehtml::elements_list result;
     litehtml::element::ptr current = element;
     while (current) {
         result.push_back(current);
@@ -60,17 +67,23 @@ static litehtml::elements_vector path(co
     return result;
 }
 
-static std::pair<litehtml::element::ptr, size_t> getCommonParent(const litehtml::elements_vector &a,
-                                                                 const litehtml::elements_vector &b)
+// <parent, first_different_child_a, first_different_child_b>
+static std::tuple<litehtml::element::ptr, litehtml::element::ptr, litehtml::element::ptr>
+getCommonParent(const litehtml::elements_list &a, const litehtml::elements_list &b)
 {
     litehtml::element::ptr parent;
-    const size_t minSize = std::min(a.size(), b.size());
-    for (size_t i = 0; i < minSize; ++i) {
-        if (a.at(i) != b.at(i))
-            return {parent, i};
-        parent = a.at(i);
-    }
-    return {parent, minSize};
+    auto ait = a.cbegin();
+    auto bit = b.cbegin();
+    while (ait != a.cend() && bit != b.cend()) {
+        if (*ait != *bit)
+            return {parent, *ait, *bit};
+        parent = *ait;
+        ++ait;
+        ++bit;
+    }
+    return {parent,
+            (ait != a.cend() ? *ait : litehtml::element::ptr()),
+            (bit != b.cend() ? *bit : litehtml::element::ptr())};
 }
 
 static std::pair<Selection::Element, Selection::Element> getStartAndEnd(const Selection::Element &a,
@@ -81,11 +94,12 @@ static std::pair<Selection::Element, Sel
             return {a, b};
         return {b, a};
     }
-    const litehtml::elements_vector aPath = path(a.element);
-    const litehtml::elements_vector bPath = path(b.element);
+    const litehtml::elements_list aPath = path(a.element);
+    const litehtml::elements_list bPath = path(b.element);
     litehtml::element::ptr commonParent;
-    size_t firstDifferentIndex;
-    std::tie(commonParent, firstDifferentIndex) = getCommonParent(aPath, bPath);
+    litehtml::element::ptr aBranch;
+    litehtml::element::ptr bBranch;
+    std::tie(commonParent, aBranch, bBranch) = getCommonParent(aPath, bPath);
     if (!commonParent) {
         qWarning() << "internal error: litehtml elements do not have common parent";
         return {a, b};
@@ -95,10 +109,7 @@ static std::pair<Selection::Element, Sel
     if (commonParent == b.element)
         return {b, b};
     // find out if a or b is first in the child sub-trees of commonParent
-    const litehtml::element::ptr aBranch = aPath.at(firstDifferentIndex);
-    const litehtml::element::ptr bBranch = bPath.at(firstDifferentIndex);
-    for (int i = 0; i < int(commonParent->get_children_count()); ++i) {
-        const litehtml::element::ptr child = commonParent->get_child(i);
+    for (const litehtml::element::ptr &child : commonParent->children()) {
         if (child == aBranch)
             return {a, b};
         if (child == bBranch)
@@ -108,14 +119,6 @@ static std::pair<Selection::Element, Sel
     return {a, b};
 }
 
-static int findChild(const litehtml::element::ptr &child, const litehtml::element::ptr &parent)
-{
-    for (int i = 0; i < int(parent->get_children_count()); ++i)
-        if (parent->get_child(i) == child)
-            return i;
-    return -1;
-}
-
 // 1) stops right away if element == stop, otherwise stops whenever stop element is encountered
 // 2) moves down the first children from element until there is none anymore
 static litehtml::element::ptr firstLeaf(const litehtml::element::ptr &element,
@@ -124,8 +127,8 @@ static litehtml::element::ptr firstLeaf(
     if (element == stop)
         return element;
     litehtml::element::ptr current = element;
-    while (current != stop && current->get_children_count() > 0)
-        current = current->get_child(0);
+    while (current != stop && !current->children().empty())
+        current = current->children().front();
     return current;
 }
 
@@ -138,17 +141,23 @@ static litehtml::element::ptr nextLeaf(c
     if (element == stop)
         return element;
     litehtml::element::ptr current = element;
-    if (current->have_parent()) {
+    if (!current->is_root()) {
         // find next sibling
         const litehtml::element::ptr parent = current->parent();
-        const int childIndex = findChild(current, parent);
-        if (childIndex < 0) {
+        const litehtml::elements_list &children = parent->children();
+        auto childIt = std::find_if(children.cbegin(),
+                                    children.cend(),
+                                    [&current](const litehtml::element::ptr &e) {
+                                        return e == current;
+                                    });
+        if (childIt == children.cend()) {
             qWarning() << "internal error: filed to find litehtml child element in parent";
             return stop;
         }
-        if (childIndex + 1 >= int(parent->get_children_count())) // no sibling, move up
+        ++childIt;
+        if (childIt == children.cend()) // no sibling, move up
             return nextLeaf(parent, stop);
-        current = parent->get_child(childIndex + 1);
+        current = *childIt;
     }
     return firstLeaf(current, stop);
 }
@@ -158,9 +167,9 @@ static Selection::Element selectionDetai
                                            const QPoint &pos)
 {
     // shortcut, which _might_ not really be correct
-    if (element->get_children_count() > 0)
+    if (!element->children().empty())
         return {element, -1, -1}; // everything selected
-    const QFont &font = toQFont(element->get_font());
+    const QFont &font = toQFont(element->css().get_font());
     const QFontMetrics fm(font);
     int previous = 0;
     for (int i = 0; i < text.size(); ++i) {
@@ -172,48 +181,63 @@ static Selection::Element selectionDetai
     return {element, int(text.size()), previous};
 }
 
-static Selection::Element deepest_child_at_point(const litehtml::document::ptr &document,
-                                                 const QPoint &pos,
-                                                 const QPoint &viewportPos,
-                                                 Selection::Mode mode)
+// Returns whether the intended child was found and stop.
+// Does a depth-first iteration over elements that "pos" is inside, and executes
+// \a action with them. If \a action returns \c true, the iteration is stopped.
+static bool deepest_child_at_point(const litehtml::element::ptr &element,
+                                   const QPoint &pos,
+                                   const QPoint &viewportPos,
+                                   const std::function<bool(const litehtml::element::ptr &)> &action,
+                                   int level = 0)
 {
-    if (!document)
-        return {};
-
-    // the following does not find the "smallest" element, it often consists of children
-    // with individual words as text...
-    const litehtml::element::ptr element = document->root()->get_element_by_point(pos.x(),
-                                                                                  pos.y(),
-                                                                                  viewportPos.x(),
-                                                                                  viewportPos.y());
-    // ...so try to find a better match
-    const std::function<Selection::Element(litehtml::element::ptr, QRect)> recursion =
-        [&recursion, pos, mode](const litehtml::element::ptr &element,
-                                const QRect &placement) -> Selection::Element {
-        if (!element)
-            return {};
-        Selection::Element result;
-        for (int i = 0; i < int(element->get_children_count()); ++i) {
-            const litehtml::element::ptr child = element->get_child(i);
-            result = recursion(child,
-                               toQRect(child->get_position()).translated(placement.topLeft()));
-            if (result.element)
-                return result;
-        }
-        if (placement.contains(pos)) {
-            litehtml::tstring text;
-            element->get_text(text);
-            if (!text.empty()) {
-                return mode == Selection::Mode::Free
-                           ? selectionDetails(element,
-                                              QString::fromStdString(text),
-                                              pos - placement.topLeft())
-                           : Selection::Element({element, -1, -1});
-            }
-        }
-        return {};
-    };
-    return recursion(element, element ? toQRect(element->get_placement()) : QRect());
+    // TODO are there elements for which we should take viewportPos into account instead?
+    // E.g. fixed position elements?
+    if (!element)
+        return false /*continue iterating*/;
+    const QRect placement = toQRect(element->get_placement());
+    // Do not continue down elements that do not cover the position. Exceptions:
+    // - elements with 0 size (includes anchors and other weird elements)
+    // - html and body, which for some reason have size == viewport size
+    if (!placement.size().isEmpty() && element->tag() != litehtml::_html_
+        && element->tag() != litehtml::_body_ && !placement.contains(pos)) {
+        return false /*continue iterating*/;
+    }
+    // qDebug() << qPrintable(QString(level * 2, ' ')) << element->dump_get_name() << placement << pos;
+
+    const litehtml::elements_list &children = element->children();
+    for (auto it = children.cbegin(); it != children.cend(); ++it) {
+        if (deepest_child_at_point(*it, pos, viewportPos, action, level + 1))
+            return true;
+    }
+    if (placement.contains(pos))
+        return action(element);
+    return false /*continue iterating*/;
+}
+
+static Selection::Element selection_element_at_point(const litehtml::element::ptr &element,
+                                                     const QPoint &pos,
+                                                     const QPoint &viewportPos,
+                                                     Selection::Mode mode)
+{
+    Selection::Element result;
+    deepest_child_at_point(element,
+                           pos,
+                           viewportPos,
+                           [mode, &result, &pos](const litehtml::element::ptr &element) {
+                               const QRect placement = toQRect(element->get_placement());
+                               std::string text;
+                               element->get_text(text);
+                               if (!text.empty()) {
+                                   result = mode == Selection::Mode::Free
+                                                ? selectionDetails(element,
+                                                                   QString::fromStdString(text),
+                                                                   pos - placement.topLeft())
+                                                : Selection::Element({element, -1, -1});
+                                   return true;
+                               }
+                               return false; /*continue*/
+                           });
+    return result;
 }
 
 // CSS: 400 == normal, 700 == bold.
@@ -235,9 +259,9 @@ static QFont::Weight cssWeightToQtWeight
 static QFont::Style toQFontStyle(litehtml::font_style style)
 {
     switch (style) {
-    case litehtml::fontStyleNormal:
+    case litehtml::font_style_normal:
         return QFont::StyleNormal;
-    case litehtml::fontStyleItalic:
+    case litehtml::font_style_italic:
         return QFont::StyleItalic;
     }
     // should not happen
@@ -355,7 +379,7 @@ void Selection::update()
 {
     const auto addElement = [this](const Selection::Element &element,
                                    const Selection::Element &end = {}) {
-        litehtml::tstring elemText;
+        std::string elemText;
         element.element->get_text(elemText);
         const QString textStr = QString::fromStdString(elemText);
         if (!textStr.isEmpty()) {
@@ -429,7 +453,7 @@ DocumentContainer::DocumentContainer()
 
 DocumentContainer::~DocumentContainer() = default;
 
-litehtml::uint_ptr DocumentContainerPrivate::create_font(const litehtml::tchar_t *faceName,
+litehtml::uint_ptr DocumentContainerPrivate::create_font(const char *faceName,
                                                          int size,
                                                          int weight,
                                                          litehtml::font_style italic,
@@ -485,14 +509,14 @@ void DocumentContainerPrivate::delete_fo
     delete font;
 }
 
-int DocumentContainerPrivate::text_width(const litehtml::tchar_t *text, litehtml::uint_ptr hFont)
+int DocumentContainerPrivate::text_width(const char *text, litehtml::uint_ptr hFont)
 {
     const QFontMetrics fm(toQFont(hFont));
     return fm.horizontalAdvance(QString::fromUtf8(text));
 }
 
 void DocumentContainerPrivate::draw_text(litehtml::uint_ptr hdc,
-                                         const litehtml::tchar_t *text,
+                                         const char *text,
                                          litehtml::uint_ptr hFont,
                                          litehtml::web_color color,
                                          const litehtml::position &pos)
@@ -514,7 +538,7 @@ int DocumentContainerPrivate::get_defaul
     return m_defaultFont.pointSize();
 }
 
-const litehtml::tchar_t *DocumentContainerPrivate::get_default_font_name() const
+const char *DocumentContainerPrivate::get_default_font_name() const
 {
     return m_defaultFontFamilyName.constData();
 }
@@ -551,9 +575,7 @@ void DocumentContainerPrivate::draw_list
     }
 }
 
-void DocumentContainerPrivate::load_image(const litehtml::tchar_t *src,
-                                          const litehtml::tchar_t *baseurl,
-                                          bool redraw_on_ready)
+void DocumentContainerPrivate::load_image(const char *src, const char *baseurl, bool redraw_on_ready)
 {
     const auto qtSrc = QString::fromUtf8(src);
     const auto qtBaseUrl = QString::fromUtf8(baseurl);
@@ -569,8 +591,8 @@ void DocumentContainerPrivate::load_imag
     m_pixmaps.insert(url, pixmap);
 }
 
-void DocumentContainerPrivate::get_image_size(const litehtml::tchar_t *src,
-                                              const litehtml::tchar_t *baseurl,
+void DocumentContainerPrivate::get_image_size(const char *src,
+                                              const char *baseurl,
                                               litehtml::size &sz)
 {
     const auto qtSrc = QString::fromUtf8(src);
@@ -617,8 +639,8 @@ void DocumentContainerPrivate::buildInde
         m_index.elementToIndex.insert({current, index});
         if (!inBody)
             inBody = tagName(current).toLower() == "body";
-        if (inBody && current->is_visible()) {
-            litehtml::tstring text;
+        if (inBody && isVisible(current)) {
+            std::string text;
             current->get_text(text);
             if (!text.empty()) {
                 m_index.indexToElement.push_back({index, current});
@@ -657,84 +679,89 @@ void DocumentContainerPrivate::clearSele
 }
 
 void DocumentContainerPrivate::draw_background(litehtml::uint_ptr hdc,
-                                               const litehtml::background_paint &bg)
+                                               const std::vector<litehtml::background_paint> &bgs)
 {
     auto painter = toQPainter(hdc);
-    if (bg.is_root) {
-        // TODO ?
-        return;
-    }
     painter->save();
-    painter->setClipRect(toQRect(bg.clip_box));
-    const QRegion horizontalMiddle(
-        QRect(bg.border_box.x,
-              bg.border_box.y + bg.border_radius.top_left_y,
-              bg.border_box.width,
-              bg.border_box.height - bg.border_radius.top_left_y - bg.border_radius.bottom_left_y));
-    const QRegion horizontalTop(
-        QRect(bg.border_box.x + bg.border_radius.top_left_x,
-              bg.border_box.y,
-              bg.border_box.width - bg.border_radius.top_left_x - bg.border_radius.top_right_x,
-              bg.border_radius.top_left_y));
-    const QRegion horizontalBottom(QRect(bg.border_box.x + bg.border_radius.bottom_left_x,
-                                         bg.border_box.bottom() - bg.border_radius.bottom_left_y,
-                                         bg.border_box.width - bg.border_radius.bottom_left_x
-                                             - bg.border_radius.bottom_right_x,
-                                         bg.border_radius.bottom_left_y));
-    const QRegion topLeft(QRect(bg.border_box.left(),
-                                bg.border_box.top(),
-                                2 * bg.border_radius.top_left_x,
-                                2 * bg.border_radius.top_left_y),
-                          QRegion::Ellipse);
-    const QRegion topRight(QRect(bg.border_box.right() - 2 * bg.border_radius.top_right_x,
-                                 bg.border_box.top(),
-                                 2 * bg.border_radius.top_right_x,
-                                 2 * bg.border_radius.top_right_y),
-                           QRegion::Ellipse);
-    const QRegion bottomLeft(QRect(bg.border_box.left(),
-                                   bg.border_box.bottom() - 2 * bg.border_radius.bottom_left_y,
-                                   2 * bg.border_radius.bottom_left_x,
-                                   2 * bg.border_radius.bottom_left_y),
-                             QRegion::Ellipse);
-    const QRegion bottomRight(QRect(bg.border_box.right() - 2 * bg.border_radius.bottom_right_x,
-                                    bg.border_box.bottom() - 2 * bg.border_radius.bottom_right_y,
-                                    2 * bg.border_radius.bottom_right_x,
-                                    2 * bg.border_radius.bottom_right_y),
+    for (const litehtml::background_paint &bg : bgs) {
+        if (bg.is_root) {
+            // TODO ?
+            break;
+        }
+        painter->setClipRect(toQRect(bg.clip_box));
+        const QRegion horizontalMiddle(QRect(bg.border_box.x,
+                                             bg.border_box.y + bg.border_radius.top_left_y,
+                                             bg.border_box.width,
+                                             bg.border_box.height - bg.border_radius.top_left_y
+                                                 - bg.border_radius.bottom_left_y));
+        const QRegion horizontalTop(
+            QRect(bg.border_box.x + bg.border_radius.top_left_x,
+                  bg.border_box.y,
+                  bg.border_box.width - bg.border_radius.top_left_x - bg.border_radius.top_right_x,
+                  bg.border_radius.top_left_y));
+        const QRegion horizontalBottom(QRect(bg.border_box.x + bg.border_radius.bottom_left_x,
+                                             bg.border_box.bottom() - bg.border_radius.bottom_left_y,
+                                             bg.border_box.width - bg.border_radius.bottom_left_x
+                                                 - bg.border_radius.bottom_right_x,
+                                             bg.border_radius.bottom_left_y));
+        const QRegion topLeft(QRect(bg.border_box.left(),
+                                    bg.border_box.top(),
+                                    2 * bg.border_radius.top_left_x,
+                                    2 * bg.border_radius.top_left_y),
                               QRegion::Ellipse);
-    const QRegion clipRegion = horizontalMiddle.united(horizontalTop)
-                                   .united(horizontalBottom)
-                                   .united(topLeft)
-                                   .united(topRight)
-                                   .united(bottomLeft)
-                                   .united(bottomRight);
-    painter->setClipRegion(clipRegion, Qt::IntersectClip);
-    painter->setPen(Qt::NoPen);
-    painter->setBrush(toQColor(bg.color));
-    painter->drawRect(bg.border_box.x, bg.border_box.y, bg.border_box.width, bg.border_box.height);
-    drawSelection(painter, toQRect(bg.border_box));
-    if (!bg.image.empty()) {
-        const QPixmap pixmap = getPixmap(QString::fromStdString(bg.image),
-                                         QString::fromStdString(bg.baseurl));
-        if (bg.repeat == litehtml::background_repeat_no_repeat) {
-            painter->drawPixmap(QRect(bg.position_x,
-                                      bg.position_y,
-                                      bg.image_size.width,
-                                      bg.image_size.height),
-                                pixmap);
-        } else if (bg.repeat == litehtml::background_repeat_repeat_x) {
-            if (bg.image_size.width > 0) {
-                int x = bg.border_box.left();
-                while (x <= bg.border_box.right()) {
-                    painter->drawPixmap(QRect(x,
-                                              bg.border_box.top(),
-                                              bg.image_size.width,
-                                              bg.image_size.height),
-                                        pixmap);
-                    x += bg.image_size.width;
+        const QRegion topRight(QRect(bg.border_box.right() - 2 * bg.border_radius.top_right_x,
+                                     bg.border_box.top(),
+                                     2 * bg.border_radius.top_right_x,
+                                     2 * bg.border_radius.top_right_y),
+                               QRegion::Ellipse);
+        const QRegion bottomLeft(QRect(bg.border_box.left(),
+                                       bg.border_box.bottom() - 2 * bg.border_radius.bottom_left_y,
+                                       2 * bg.border_radius.bottom_left_x,
+                                       2 * bg.border_radius.bottom_left_y),
+                                 QRegion::Ellipse);
+        const QRegion bottomRight(QRect(bg.border_box.right() - 2 * bg.border_radius.bottom_right_x,
+                                        bg.border_box.bottom() - 2 * bg.border_radius.bottom_right_y,
+                                        2 * bg.border_radius.bottom_right_x,
+                                        2 * bg.border_radius.bottom_right_y),
+                                  QRegion::Ellipse);
+        const QRegion clipRegion = horizontalMiddle.united(horizontalTop)
+                                       .united(horizontalBottom)
+                                       .united(topLeft)
+                                       .united(topRight)
+                                       .united(bottomLeft)
+                                       .united(bottomRight);
+        painter->setClipRegion(clipRegion, Qt::IntersectClip);
+        painter->setPen(Qt::NoPen);
+        painter->setBrush(toQColor(bg.color));
+        painter->drawRect(bg.border_box.x,
+                          bg.border_box.y,
+                          bg.border_box.width,
+                          bg.border_box.height);
+        drawSelection(painter, toQRect(bg.border_box));
+        if (!bg.image.empty()) {
+            const QPixmap pixmap = getPixmap(QString::fromStdString(bg.image),
+                                             QString::fromStdString(bg.baseurl));
+            if (bg.repeat == litehtml::background_repeat_no_repeat) {
+                painter->drawPixmap(QRect(bg.position_x,
+                                          bg.position_y,
+                                          bg.image_size.width,
+                                          bg.image_size.height),
+                                    pixmap);
+            } else if (bg.repeat == litehtml::background_repeat_repeat_x) {
+                if (bg.image_size.width > 0) {
+                    int x = bg.border_box.left();
+                    while (x <= bg.border_box.right()) {
+                        painter->drawPixmap(QRect(x,
+                                                  bg.border_box.top(),
+                                                  bg.image_size.width,
+                                                  bg.image_size.height),
+                                            pixmap);
+                        x += bg.image_size.width;
+                    }
                 }
+            } else {
+                qWarning(log) << "unsupported background repeat" << bg.repeat;
             }
-        } else {
-            qWarning(log) << "unsupported background repeat" << bg.repeat;
         }
     }
     painter->restore();
@@ -806,12 +833,12 @@ void DocumentContainerPrivate::draw_bord
     }
 }
 
-void DocumentContainerPrivate::set_caption(const litehtml::tchar_t *caption)
+void DocumentContainerPrivate::set_caption(const char *caption)
 {
     m_caption = QString::fromUtf8(caption);
 }
 
-void DocumentContainerPrivate::set_base_url(const litehtml::tchar_t *base_url)
+void DocumentContainerPrivate::set_base_url(const char *base_url)
 {
     m_baseUrl = QString::fromUtf8(base_url);
 }
@@ -825,20 +852,19 @@ void DocumentContainerPrivate::link(cons
     Q_UNUSED(el)
 }
 
-void DocumentContainerPrivate::on_anchor_click(const litehtml::tchar_t *url,
-                                               const litehtml::element::ptr &el)
+void DocumentContainerPrivate::on_anchor_click(const char *url, const litehtml::element::ptr &el)
 {
     Q_UNUSED(el)
     if (!m_blockLinks)
         m_linkCallback(resolveUrl(QString::fromUtf8(url), m_baseUrl));
 }
 
-void DocumentContainerPrivate::set_cursor(const litehtml::tchar_t *cursor)
+void DocumentContainerPrivate::set_cursor(const char *cursor)
 {
     m_cursorCallback(toQCursor(QString::fromUtf8(cursor)));
 }
 
-void DocumentContainerPrivate::transform_text(litehtml::tstring &text, litehtml::text_transform tt)
+void DocumentContainerPrivate::transform_text(std::string &text, litehtml::text_transform tt)
 {
     // TODO
     qDebug(log) << "transform_text";
@@ -846,9 +872,9 @@ void DocumentContainerPrivate::transform
     Q_UNUSED(tt)
 }
 
-void DocumentContainerPrivate::import_css(litehtml::tstring &text,
-                                          const litehtml::tstring &url,
-                                          litehtml::tstring &baseurl)
+void DocumentContainerPrivate::import_css(std::string &text,
+                                          const std::string &url,
+                                          std::string &baseurl)
 {
     const QUrl actualUrl = resolveUrl(QString::fromStdString(url), QString::fromStdString(baseurl));
     const QString urlString = actualUrl.toString(QUrl::None);
@@ -858,16 +884,12 @@ void DocumentContainerPrivate::import_cs
 }
 
 void DocumentContainerPrivate::set_clip(const litehtml::position &pos,
-                                        const litehtml::border_radiuses &bdr_radius,
-                                        bool valid_x,
-                                        bool valid_y)
+                                        const litehtml::border_radiuses &bdr_radius)
 {
     // TODO
     qDebug(log) << "set_clip";
     Q_UNUSED(pos)
     Q_UNUSED(bdr_radius)
-    Q_UNUSED(valid_x)
-    Q_UNUSED(valid_y)
 }
 
 void DocumentContainerPrivate::del_clip()
@@ -882,7 +904,7 @@ void DocumentContainerPrivate::get_clien
 }
 
 std::shared_ptr<litehtml::element> DocumentContainerPrivate::create_element(
-    const litehtml::tchar_t *tag_name,
+    const char *tag_name,
     const litehtml::string_map &attributes,
     const std::shared_ptr<litehtml::document> &doc)
 {
@@ -900,7 +922,7 @@ void DocumentContainerPrivate::get_media
     qDebug(log) << "get_media_features";
 }
 
-void DocumentContainerPrivate::get_language(litehtml::tstring &language, litehtml::tstring &culture) const
+void DocumentContainerPrivate::get_language(std::string &language, std::string &culture) const
 {
     // TODO
     qDebug(log) << "get_language";
@@ -922,7 +944,9 @@ void DocumentContainer::setDocument(cons
 {
     d->m_pixmaps.clear();
     d->clearSelection();
-    d->m_document = litehtml::document::createFromUTF8(data.constData(), d.get(), &context->d->context);
+    d->m_document = litehtml::document::createFromString(data.constData(),
+                                                         d.get(),
+                                                         context->d->masterCss.toUtf8().constData());
     d->buildIndex();
 }
 
@@ -987,10 +1011,10 @@ QVector<QRect> DocumentContainer::mouseP
         redrawRects.append(d->m_selection.boundingRect());
     d->clearSelection();
     d->m_selection.selectionStartDocumentPos = documentPos;
-    d->m_selection.startElem = deepest_child_at_point(d->m_document,
-                                                      documentPos,
-                                                      viewportPos,
-                                                      d->m_selection.mode);
+    d->m_selection.startElem = selection_element_at_point(d->m_document->root(),
+                                                          documentPos,
+                                                          viewportPos,
+                                                          d->m_selection.mode);
     // post to litehtml
     litehtml::position::vector redrawBoxes;
     if (d->m_document->on_lbutton_down(
@@ -1012,10 +1036,10 @@ QVector<QRect> DocumentContainer::mouseM
         || (!d->m_selection.selectionStartDocumentPos.isNull()
             && (d->m_selection.selectionStartDocumentPos - documentPos).manhattanLength() >= kDragDistance
             && d->m_selection.startElem.element)) {
-        const Selection::Element element = deepest_child_at_point(d->m_document,
-                                                                  documentPos,
-                                                                  viewportPos,
-                                                                  d->m_selection.mode);
+        const Selection::Element element = selection_element_at_point(d->m_document->root(),
+                                                                      documentPos,
+                                                                      viewportPos,
+                                                                      d->m_selection.mode);
         if (element.element) {
             redrawRects.append(
                 d->m_selection.boundingRect() /*.adjusted(-1, -1, +1, +1)*/); // redraw old selection area
@@ -1067,10 +1091,10 @@ QVector<QRect> DocumentContainer::mouseD
     QVector<QRect> redrawRects;
     d->clearSelection();
     d->m_selection.mode = Selection::Mode::Word;
-    const Selection::Element element = deepest_child_at_point(d->m_document,
-                                                              documentPos,
-                                                              viewportPos,
-                                                              d->m_selection.mode);
+    const Selection::Element element = selection_element_at_point(d->m_document->root(),
+                                                                  documentPos,
+                                                                  viewportPos,
+                                                                  d->m_selection.mode);
     if (element.element) {
         d->m_selection.startElem = element;
         d->m_selection.endElem = d->m_selection.startElem;
@@ -1104,11 +1128,19 @@ QUrl DocumentContainer::linkAt(const QPo
 {
     if (!d->m_document)
         return {};
-    const litehtml::element::ptr element = d->m_document->root()->get_element_by_point(
-        documentPos.x(), documentPos.y(), viewportPos.x(), viewportPos.y());
-    if (!element)
-        return {};
-    const char *href = element->get_attr("href");
+    const char *href = nullptr;
+    deepest_child_at_point(d->m_document->root(),
+                           documentPos,
+                           viewportPos,
+                           [&href](const litehtml::element::ptr &e) {
+                               const litehtml::element::ptr parent = e->parent();
+                               if (parent && parent->tag() == litehtml::_a_) {
+                                   href = parent->get_attr("href");
+                                   if (href)
+                                       return true;
+                               }
+                               return false; /*continue*/
+                           });
     if (href)
         return d->resolveUrl(QString::fromUtf8(href), d->m_baseUrl);
     return {};
@@ -1171,10 +1203,10 @@ void DocumentContainer::findText(const Q
     }
 
     const auto fillXPos = [](const Selection::Element &e) {
-        litehtml::tstring ttext;
+        std::string ttext;
         e.element->get_text(ttext);
         const QString text = QString::fromStdString(ttext);
-        const QFont &font = toQFont(e.element->get_font());
+        const QFont &font = toQFont(e.element->css().get_font());
         const QFontMetrics fm(font);
         return Selection::Element{e.element, e.index, fm.size(0, text.left(e.index)).width()};
     };
@@ -1226,7 +1258,7 @@ void DocumentContainer::setDefaultFont(c
     // we need to trigger the reparse of this info.
     if (d->m_document && d->m_document->root()) {
         d->m_document->root()->refresh_styles();
-        d->m_document->root()->parse_styles();
+        d->m_document->root()->compute_styles();
     }
 }
 
@@ -1260,27 +1292,26 @@ void DocumentContainer::setClipboardCall
     d->m_clipboardCallback = callback;
 }
 
+static litehtml::element::ptr elementForY(int y, const litehtml::element::ptr &element)
+{
+    if (!element)
+        return {};
+    if (element->get_placement().y >= y)
+        return element;
+    for (const litehtml::element::ptr &child : element->children()) {
+        litehtml::element::ptr result = elementForY(y, child);
+        if (result)
+            return result;
+    }
+    return {};
+}
+
 static litehtml::element::ptr elementForY(int y, const litehtml::document::ptr &document)
 {
     if (!document)
         return {};
 
-    const std::function<litehtml::element::ptr(int, litehtml::element::ptr)> recursion =
-        [&recursion](int y, const litehtml::element::ptr &element) {
-            litehtml::element::ptr result;
-            const int subY = y - element->get_position().y;
-            if (subY <= 0)
-                return element;
-            for (int i = 0; i < int(element->get_children_count()); ++i) {
-                const litehtml::element::ptr child = element->get_child(i);
-                result = recursion(subY, child);
-                if (result)
-                    return result;
-            }
-            return result;
-        };
-
-    return recursion(y, document->root());
+    return elementForY(y, document->root());
 }
 
 int DocumentContainer::withFixedElementPosition(int y, const std::function<void()> &action)
@@ -1368,5 +1399,5 @@ DocumentContainerContext::~DocumentConta
 
 void DocumentContainerContext::setMasterStyleSheet(const QString &css)
 {
-    d->context.load_master_stylesheet(css.toUtf8().constData());
+    d->masterCss = css;
 }
