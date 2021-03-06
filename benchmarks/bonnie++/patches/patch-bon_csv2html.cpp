$NetBSD: patch-bon_csv2html.cpp,v 1.1 2021/07/10 01:43:57 markd Exp $

rename data for gcc-11

--- bon_csv2html.cpp.orig	2018-09-13 14:54:36.000000000 +0000
+++ bon_csv2html.cpp
@@ -10,7 +10,7 @@
 using namespace std;
 typedef vector<PCCHAR> STR_VEC;
 
-vector<STR_VEC> data;
+vector<STR_VEC> stddata;
 typedef PCCHAR * PPCCHAR;
 PPCCHAR * props;
 
@@ -87,8 +87,8 @@ int main(int argc, char **argv)
     read_in(buf);
   }
 
-  props = new PPCCHAR[data.size()];
-  for(i = 0; i < data.size(); i++)
+  props = new PPCCHAR[stddata.size()];
+  for(i = 0; i < stddata.size(); i++)
   {
     props[i] = new PCCHAR[MAX_ITEMS];
     props[i][0] = NULL;
@@ -109,7 +109,7 @@ int main(int argc, char **argv)
   }
   calc_vals();
   int mid_width = header();
-  for(i = 0; i < data.size(); i++)
+  for(i = 0; i < stddata.size(); i++)
   {
 // First print the average speed line
     printf("<tr>");
@@ -171,23 +171,23 @@ int compar(const void *a, const void *b)
 
 void calc_vals()
 {
-  ITEM *arr = new ITEM[data.size()];
+  ITEM *arr = new ITEM[stddata.size()];
   for(unsigned int column_ind = 0; column_ind < MAX_ITEMS; column_ind++)
   {
     switch(vals[column_ind])
     {
     case eNoCols:
     {
-      for(unsigned int row_ind = 0; row_ind < data.size(); row_ind++)
+      for(unsigned int row_ind = 0; row_ind < stddata.size(); row_ind++)
       {
         if(column_ind == COL_CONCURRENCY)
         {
-          if(data[row_ind][column_ind] && strcmp("1", data[row_ind][column_ind]))
+          if(stddata[row_ind][column_ind] && strcmp("1", stddata[row_ind][column_ind]))
             col_used[column_ind] = true;
         }
         else
         {
-          if(data[row_ind][column_ind] && strlen(data[row_ind][column_ind]))
+          if(stddata[row_ind][column_ind] && strlen(stddata[row_ind][column_ind]))
             col_used[column_ind] = true;
         }
       }
@@ -195,22 +195,22 @@ void calc_vals()
     break;
     case eCPU:
     {
-      for(unsigned int row_ind = 0; row_ind < data.size(); row_ind++)
+      for(unsigned int row_ind = 0; row_ind < stddata.size(); row_ind++)
       {
         double work, cpu;
         arr[row_ind].val = 0.0;
-        if(data[row_ind].size() > column_ind
-         && sscanf(data[row_ind][column_ind - 1], "%lf", &work) == 1
-         && sscanf(data[row_ind][column_ind], "%lf", &cpu) == 1)
+        if(stddata[row_ind].size() > column_ind
+         && sscanf(stddata[row_ind][column_ind - 1], "%lf", &work) == 1
+         && sscanf(stddata[row_ind][column_ind], "%lf", &cpu) == 1)
         {
           arr[row_ind].val = cpu / work;
         }
         arr[row_ind].pos = row_ind;
       }
-      qsort(arr, data.size(), sizeof(ITEM), compar);
+      qsort(arr, stddata.size(), sizeof(ITEM), compar);
       int col_count = -1;
       double min_col = -1.0, max_col = -1.0;
-      for(unsigned int sort_ind = 0; sort_ind < data.size(); sort_ind++)
+      for(unsigned int sort_ind = 0; sort_ind < stddata.size(); sort_ind++)
       {
         // if item is different from previous or if the first row
         // (sort_ind == 0) then increment col count
@@ -239,7 +239,7 @@ void calc_vals()
           min_col /= mult;
         }
         double range_col = max_col - min_col;
-        for(unsigned int sort_ind = 0; sort_ind < data.size(); sort_ind++)
+        for(unsigned int sort_ind = 0; sort_ind < stddata.size(); sort_ind++)
         {
           if(arr[sort_ind].col_ind > -1)
           {
@@ -250,7 +250,7 @@ void calc_vals()
       }
       else
       {
-        for(unsigned int sort_ind = 0; sort_ind < data.size(); sort_ind++)
+        for(unsigned int sort_ind = 0; sort_ind < stddata.size(); sort_ind++)
         {
           if(vals[column_ind] == eLatency)
           {
@@ -263,25 +263,25 @@ void calc_vals()
     case eSpeed:
     case eLatency:
     {
-      for(unsigned int row_ind = 0; row_ind < data.size(); row_ind++)
+      for(unsigned int row_ind = 0; row_ind < stddata.size(); row_ind++)
       {
         arr[row_ind].val = 0.0;
-        if(data[row_ind].size() <= column_ind
-         || sscanf(data[row_ind][column_ind], "%lf", &arr[row_ind].val) == 0)
+        if(stddata[row_ind].size() <= column_ind
+         || sscanf(stddata[row_ind][column_ind], "%lf", &arr[row_ind].val) == 0)
           arr[row_ind].val = 0.0;
         if(vals[column_ind] == eLatency && arr[row_ind].val != 0.0)
         {
-          if(strstr(data[row_ind][column_ind], "ms"))
+          if(strstr(stddata[row_ind][column_ind], "ms"))
             arr[row_ind].val *= 1000.0;
-          else if(!strstr(data[row_ind][column_ind], "us"))
+          else if(!strstr(stddata[row_ind][column_ind], "us"))
             arr[row_ind].val *= 1000000.0; // is !us && !ms then secs!
         }
         arr[row_ind].pos = row_ind;
       }
-      qsort(arr, data.size(), sizeof(ITEM), compar);
+      qsort(arr, stddata.size(), sizeof(ITEM), compar);
       int col_count = -1;
       double min_col = -1.0, max_col = -1.0;
-      for(unsigned int sort_ind = 0; sort_ind < data.size(); sort_ind++)
+      for(unsigned int sort_ind = 0; sort_ind < stddata.size(); sort_ind++)
       {
         // if item is different from previous or if the first row
         // (sort_ind == 0) then increment col count
@@ -310,7 +310,7 @@ void calc_vals()
           min_col /= mult;
         }
         double range_col = max_col - min_col;
-        for(unsigned int sort_ind = 0; sort_ind < data.size(); sort_ind++)
+        for(unsigned int sort_ind = 0; sort_ind < stddata.size(); sort_ind++)
         {
           if(arr[sort_ind].col_ind > -1)
           {
@@ -332,7 +332,7 @@ void calc_vals()
       }
       else
       {
-        for(unsigned int sort_ind = 0; sort_ind < data.size(); sort_ind++)
+        for(unsigned int sort_ind = 0; sort_ind < stddata.size(); sort_ind++)
         {
           if(vals[column_ind] == eLatency)
           {
@@ -481,16 +481,16 @@ void read_in(CPCCHAR buf)
     free((void *)arr[0]);
     return;
   }
-  data.push_back(arr);
+  stddata.push_back(arr);
 }
 
 void print_item(int num, int item, CPCCHAR extra)
 {
   PCCHAR line_data;
   char buf[1024];
-  if(int(data[num].size()) > item)
+  if(int(stddata[num].size()) > item)
   {
-    line_data = data[num][item];
+    line_data = stddata[num][item];
     switch(item)
     {
     case COL_PUT_BLOCK:
