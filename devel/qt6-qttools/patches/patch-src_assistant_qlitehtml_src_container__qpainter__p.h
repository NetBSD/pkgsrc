$NetBSD: patch-src_assistant_qlitehtml_src_container__qpainter__p.h,v 1.1 2024/02/10 11:03:39 wiz Exp $

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

--- src/assistant/qlitehtml/src/container_qpainter_p.h.orig	2023-11-20 11:56:10.000000000 +0000
+++ src/assistant/qlitehtml/src/container_qpainter_p.h
@@ -58,55 +58,49 @@ struct Index
 class DocumentContainerPrivate final : public litehtml::document_container
 {
 public: // document_container API
-    litehtml::uint_ptr create_font(const litehtml::tchar_t *faceName,
+    litehtml::uint_ptr create_font(const char *faceName,
                                    int size,
                                    int weight,
                                    litehtml::font_style italic,
                                    unsigned int decoration,
                                    litehtml::font_metrics *fm) override;
     void delete_font(litehtml::uint_ptr hFont) override;
-    int text_width(const litehtml::tchar_t *text, litehtml::uint_ptr hFont) override;
+    int text_width(const char *text, litehtml::uint_ptr hFont) override;
     void draw_text(litehtml::uint_ptr hdc,
-                   const litehtml::tchar_t *text,
+                   const char *text,
                    litehtml::uint_ptr hFont,
                    litehtml::web_color color,
                    const litehtml::position &pos) override;
     int pt_to_px(int pt) const override;
     int get_default_font_size() const override;
-    const litehtml::tchar_t *get_default_font_name() const override;
+    const char *get_default_font_name() const override;
     void draw_list_marker(litehtml::uint_ptr hdc, const litehtml::list_marker &marker) override;
-    void load_image(const litehtml::tchar_t *src,
-                    const litehtml::tchar_t *baseurl,
-                    bool redraw_on_ready) override;
-    void get_image_size(const litehtml::tchar_t *src,
-                        const litehtml::tchar_t *baseurl,
-                        litehtml::size &sz) override;
-    void draw_background(litehtml::uint_ptr hdc, const litehtml::background_paint &bg) override;
+    void load_image(const char *src, const char *baseurl, bool redraw_on_ready) override;
+    void get_image_size(const char *src, const char *baseurl, litehtml::size &sz) override;
+    void draw_background(litehtml::uint_ptr hdc,
+                         const std::vector<litehtml::background_paint> &bgs) override;
     void draw_borders(litehtml::uint_ptr hdc,
                       const litehtml::borders &borders,
                       const litehtml::position &draw_pos,
                       bool root) override;
-    void set_caption(const litehtml::tchar_t *caption) override;
-    void set_base_url(const litehtml::tchar_t *base_url) override;
+    void set_caption(const char *caption) override;
+    void set_base_url(const char *base_url) override;
     void link(const std::shared_ptr<litehtml::document> &doc,
               const litehtml::element::ptr &el) override;
-    void on_anchor_click(const litehtml::tchar_t *url, const litehtml::element::ptr &el) override;
-    void set_cursor(const litehtml::tchar_t *cursor) override;
-    void transform_text(litehtml::tstring &text, litehtml::text_transform tt) override;
-    void import_css(litehtml::tstring &text,
-                    const litehtml::tstring &url,
-                    litehtml::tstring &baseurl) override;
+    void on_anchor_click(const char *url, const litehtml::element::ptr &el) override;
+    void set_cursor(const char *cursor) override;
+    void transform_text(std::string &text, litehtml::text_transform tt) override;
+    void import_css(std::string &text, const std::string &url, std::string &baseurl) override;
     void set_clip(const litehtml::position &pos,
-                  const litehtml::border_radiuses &bdr_radius,
-                  bool valid_x,
-                  bool valid_y) override;
+                  const litehtml::border_radiuses &bdr_radius) override;
     void del_clip() override;
     void get_client_rect(litehtml::position &client) const override;
-    std::shared_ptr<litehtml::element> create_element(const litehtml::tchar_t *tag_name,
-                                                      const litehtml::string_map &attributes,
-                                                      const std::shared_ptr<litehtml::document> &doc) override;
+    std::shared_ptr<litehtml::element> create_element(
+        const char *tag_name,
+        const litehtml::string_map &attributes,
+        const std::shared_ptr<litehtml::document> &doc) override;
     void get_media_features(litehtml::media_features &media) const override;
-    void get_language(litehtml::tstring &language, litehtml::tstring &culture) const override;
+    void get_language(std::string &language, std::string &culture) const override;
 
     QPixmap getPixmap(const QString &imageUrl, const QString &baseUrl);
     QString serifFont() const;
@@ -140,5 +134,5 @@ public: // document_container API
 class DocumentContainerContextPrivate
 {
 public:
-    litehtml::context context;
+    QString masterCss;
 };
