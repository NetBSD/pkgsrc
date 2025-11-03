$NetBSD: patch-munchlist.X,v 1.1 2025/11/03 15:56:55 vins Exp $

Replace deprecated `egrep' with either equivalent `grep -E'
or `grep -F' if called with a non-regexp. 

--- munchlist.X.orig	2015-02-08 08:35:41.149510902 +0000
+++ munchlist.X
@@ -549,7 +549,7 @@ case "$flagmarker" in
 esac    
 #
 # Munch the input to generate roots and affixes ($ISPELL -c).  We are
-# only interested in words that have at least one affix (egrep $flagmarker);
+# only interested in words that have at least one affix (grep -E $flagmarker);
 # the next step will pick up the rest.  Some of the roots are illegal.  We
 # use join to restrict the output to those root words that are found
 # in the original dictionary.
@@ -564,7 +564,7 @@ fi
 $ISPELL "$wchars" -c -W0 -d $FAKEHASH -p /dev/null < $STRIPPEDINPUT \
   | tr " " '
 ' \
-  | egrep "$flagmarker" | sort $SORTTMP -u "-t$flagmarker" $sortopts \
+  | grep -E "$flagmarker" | sort $SORTTMP -u "-t$flagmarker" $sortopts \
   | $JOIN $SIGNED "-t$flagmarker" - $EXPANDEDINPUT > $CRUNCHEDINPUT
 #
 # We now have a list of legal roots, and of affixes that apply to the
@@ -668,8 +668,8 @@ $ISPELL -D -d $FAKEHASH \
   | tr '	' ' ' \
   | sort $SORTTMP $sortopts > $PRODUCTLIST
 
-if [ `egrep ' p ' $PRODUCTLIST | wc -l` -gt 0 \
-  -a `egrep ' s ' $PRODUCTLIST | wc -l` -gt 0 ]
+if [ `grep -F ' p ' $PRODUCTLIST | wc -l` -gt 0 \
+  -a `grep -F ' s ' $PRODUCTLIST | wc -l` -gt 0 ]
 then
     #
     # The language tables allow cross products.  See if LEGALFLAGLIST has
@@ -680,7 +680,7 @@ then
 '`
     sufflags=`sed -n -e 's/^[ 0-9]*s //p' $PRODUCTLIST | tr -d '
 '`
-    egrep "$flagmarker.*[$preflags].*[$sufflags]|$flagmarker.*[$sufflags].*[$preflags]" \
+    grep -E "$flagmarker.*[$preflags].*[$sufflags]|$flagmarker.*[$sufflags].*[$preflags]" \
       $LEGALFLAGLIST \
       > $CROSSROOTS
 
