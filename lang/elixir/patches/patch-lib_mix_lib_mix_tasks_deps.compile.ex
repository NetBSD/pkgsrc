$NetBSD: patch-lib_mix_lib_mix_tasks_deps.compile.ex,v 1.1 2020/09/11 15:05:06 nia Exp $

make on NetBSD is also BSD make.

--- lib/mix/lib/mix/tasks/deps.compile.ex.orig	2020-07-04 11:10:47.000000000 +0000
+++ lib/mix/lib/mix/tasks/deps.compile.ex
@@ -244,7 +244,7 @@ defmodule Mix.Tasks.Deps.Compile do
         {:win32, _} when makefile_win? ->
           "nmake /F Makefile.win"
 
-        {:unix, type} when type in [:freebsd, :openbsd] ->
+        {:unix, type} when type in [:freebsd, :netbsd, :openbsd] ->
           "gmake"
 
         _ ->
