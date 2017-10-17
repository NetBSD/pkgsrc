$NetBSD: patch-lib_compiler_src_beam__validator.erl,v 1.1 2017/10/17 14:47:36 fhajny Exp $

Fix incorrect internal consistency failure for binary matching code.
Backport from trunk as per https://bugs.erlang.org/browse/ERL-490.

--- lib/compiler/src/beam_validator.erl.orig	2017-09-25 19:10:38.000000000 +0000
+++ lib/compiler/src/beam_validator.erl
@@ -1430,13 +1430,13 @@ merge_types(bool, {atom,A}) ->
     merge_bool(A);
 merge_types({atom,A}, bool) ->
     merge_bool(A);
-merge_types(#ms{id=Id1,valid=B0,slots=Slots},
-	    #ms{id=Id2,valid=B1,slots=Slots}) ->
+merge_types(#ms{id=Id1,valid=B1,slots=Slots1},
+	    #ms{id=Id2,valid=B2,slots=Slots2}) ->
     Id = if
              Id1 =:= Id2 -> Id1;
              true -> make_ref()
          end,
-    #ms{id=Id,valid=B0 band B1,slots=Slots};
+    #ms{id=Id,valid=B1 band B2,slots=min(Slots1, Slots2)};
 merge_types(T1, T2) when T1 =/= T2 ->
     %% Too different. All we know is that the type is a 'term'.
     term.
