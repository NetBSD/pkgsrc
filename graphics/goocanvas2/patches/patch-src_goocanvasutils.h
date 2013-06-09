$NetBSD: patch-src_goocanvasutils.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasutils.h.orig	2011-10-01 11:41:10.000000000 +0000
+++ src/goocanvasutils.h
@@ -17,7 +17,8 @@ G_BEGIN_DECLS
  */
 
 /**
- * GooCanvasPointerEvents
+ * GooCanvasPointerEvents:
+ *
  * @GOO_CANVAS_EVENTS_VISIBLE_MASK: a mask indicating that the item only
  *  receives events when it is visible.
  * @GOO_CANVAS_EVENTS_PAINTED_MASK: a mask indicating that the item only
@@ -66,7 +67,8 @@ typedef enum
 
 
 /**
- * GooCanvasItemVisibility
+ * GooCanvasItemVisibility:
+ *
  * @GOO_CANVAS_ITEM_HIDDEN: the item is invisible, and is not allocated any
  *  space in layout container items such as #GooCanvasTable.
  * @GOO_CANVAS_ITEM_INVISIBLE: the item is invisible, but it is still allocated
@@ -91,7 +93,8 @@ typedef enum
 
 
 /**
- * GooCanvasPathCommandType
+ * GooCanvasPathCommandType:
+ *
  * @GOO_CANVAS_PATH_MOVE_TO: move to the given point.
  * @GOO_CANVAS_PATH_CLOSE_PATH: close the current path, drawing a line from the
  *  current position to the start of the path.
@@ -140,7 +143,8 @@ typedef enum
 
 
 /**
- * GooCanvasAnchorType
+ * GooCanvasAnchorType:
+ *
  * @GOO_CANVAS_ANCHOR_CENTER: the anchor is in the center of the object.
  * @GOO_CANVAS_ANCHOR_NORTH: the anchor is at the top of the object, centered horizontally.
  * @GOO_CANVAS_ANCHOR_NORTH_WEST: the anchor is at the top-left of the object.
@@ -189,7 +193,7 @@ typedef union _GooCanvasPathCommand  Goo
    we can always use it whatever type of command it is. */
 
 /**
- * GooCanvasPathCommand
+ * GooCanvasPathCommand:
  *
  * GooCanvasPathCommand holds the data for each command in the path.
  *
@@ -235,7 +239,8 @@ void	goo_canvas_create_path		(GArray		  
 typedef struct _GooCanvasLineDash GooCanvasLineDash;
 
 /**
- * GooCanvasLineDash
+ * GooCanvasLineDash:
+ *
  * @ref_count: the reference count of the struct.
  * @num_dashes: the number of dashes and gaps between them.
  * @dashes: the sizes of each dash and gap.
@@ -266,7 +271,7 @@ typedef cairo_pattern_t		GooCairoPattern
 #endif
 
 /**
- * GooCairoAntialias
+ * GooCairoAntialias:
  *
  * #GooCairoAntialias is simply a wrapper for the #cairo_antialias_t type,
  * allowing it to be used for #GObject properties.
@@ -275,7 +280,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoFillRule
+ * GooCairoFillRule:
  *
  * #GooCairoFillRule is simply a wrapper for the #cairo_fill_rule_t type,
  * allowing it to be used for #GObject properties.
@@ -284,7 +289,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoHintMetrics
+ * GooCairoHintMetrics:
  *
  * #GooCairoHintMetrics is simply a wrapper for the #cairo_hint_metrics_t type,
  * allowing it to be used for #GObject properties.
@@ -293,7 +298,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoLineCap
+ * GooCairoLineCap:
  *
  * #GooCairoLineCap is simply a wrapper for the #cairo_line_cap_t type,
  * allowing it to be used for #GObject properties.
@@ -302,7 +307,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoLineJoin
+ * GooCairoLineJoin:
  *
  * #GooCairoLineJoin is simply a wrapper for the #cairo_line_join_t type,
  * allowing it to be used for #GObject properties.
@@ -311,7 +316,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoOperator
+ * GooCairoOperator:
  *
  * #GooCairoOperator is simply a wrapper for the #cairo_operator_t type,
  * allowing it to be used for #GObject properties.
@@ -320,7 +325,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoMatrix
+ * GooCairoMatrix:
  *
  * #GooCairoMatrix is simply a wrapper for the #cairo_matrix_t type,
  * allowing it to be used for #GObject properties.
@@ -329,7 +334,7 @@ typedef cairo_pattern_t		GooCairoPattern
  */
 
 /**
- * GooCairoPattern
+ * GooCairoPattern:
  *
  * #GooCairoPattern is simply a wrapper for the #cairo_pattern_t type,
  * allowing it to be used for #GObject properties.
