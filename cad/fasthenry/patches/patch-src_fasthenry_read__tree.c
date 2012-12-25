$NetBSD: patch-src_fasthenry_read__tree.c,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/read_tree.c.orig	2012-12-25 16:18:18.000000000 +0000
+++ src/fasthenry/read_tree.c
@@ -44,6 +44,11 @@ operation of Software or Licensed Progra
   
 #define MAXLINE 1000
 
+static void replace_node(G_nodes *old_node, G_nodes *new_node);
+static void dump_leaf_cells_to_file(Gcell *cell, char *fname);
+static void compute_z_fils(Nonuni_gp *gp);
+static void remove_and_free(G_nodes *node);
+
 process_plane(grndp, fp, indsys)
      GROUNDPLANE *grndp;
      FILE *fp;
@@ -929,8 +934,7 @@ combine_nodes(leafcell, leafdir, fareast
 
 /* replace the cell's node in the node_dir direction with new node
    */
-replace_node(old_node, new_node)
-     G_nodes *new_node, *old_node;
+static void replace_node(G_nodes *old_node, G_nodes *new_node)
 {
   int i;
 
@@ -1015,8 +1019,7 @@ delete_dead_nodes(gp)
   }
 }
 
-remove_and_free(node)
-     G_nodes *node;
+static void remove_and_free(G_nodes *node)
 {
 
   if (node->prev != NULL)
@@ -1140,8 +1143,7 @@ G_nodes *get_other_gnode(cell, edge_dir,
   
 }
 
-compute_z_fils(gp)
-     Nonuni_gp *gp;
+static void compute_z_fils(Nonuni_gp *gp)
 {
   double *z_c, *thick, *z_pts, thickness;
   int num_z_pts;
@@ -1704,9 +1706,7 @@ debug_func()
   i = 0;
 }
 
-dump_leaf_cells_to_file(cell, fname)
-     Gcell *cell;
-     char *fname;
+static void dump_leaf_cells_to_file(Gcell *cell, char *fname)
 {
   FILE *fp;
 
