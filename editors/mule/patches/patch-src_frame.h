$NetBSD: patch-src_frame.h,v 1.1 2013/04/21 15:39:59 joerg Exp $

--- src/frame.h.orig	1994-10-21 04:20:17.000000000 +0000
+++ src/frame.h
@@ -286,6 +286,8 @@ struct frame
 
 typedef struct frame *FRAME_PTR;
 
+void change_frame_size (FRAME_PTR frame, int newheight, int newwidth, int pretend, int delay);
+
 #define XFRAME(p) ((struct frame *) XPNTR (p))
 #define XSETFRAME(p, v) ((struct frame *) XSETPNTR (p, v))
 
@@ -427,6 +429,29 @@ extern Lisp_Object Vframe_list;
 extern Lisp_Object Vdefault_frame_alist;
 
 extern Lisp_Object Vterminal_frame;
+
+void set_window_width (Lisp_Object window, int width, int nodelete);
+void set_window_height (Lisp_Object window, int height, int nodelete);
+void write_glyphs (GLYPH *string, int len);
+void insert_glyphs (GLYPH *start, int len);
+void clear_frame(void);
+void delete_glyphs(int n);
+void ins_del_lines (int vpos, int n);
+void calculate_costs(FRAME_PTR frame);
+void cursor_to (int row, int col);
+void change_line_highlight (int new_highlight, int vpos, int first_unused_hpos);
+void update_end (FRAME_PTR f);
+void set_terminal_window (int size);
+void reassert_line_highlight(int highlight, int vpos);
+void ring_bell(void);
+void set_terminal_modes(void);
+void reset_terminal_modes(void);
+void x_iconify_frame(struct frame *f);
+void discard_tty_input (void);
+void init_sys_modes(void);
+void reset_sys_modes(void);
+void del_range_1 (int from, int to, int prepare);
+void del_range (int from, int to);
 
 #else /* not MULTI_FRAME */
 
