# $NetBSD: varmod-root.mk,v 1.2 2024/09/17 11:52:34 jperkin Exp $
#
# Tests for the :R variable modifier, which returns the filename root
# without the extension.

.if ${a/b/c:L:R} != "a/b/c"
.  error
.endif

.if ${def:L:R} != "def"
.  error
.endif

.if ${a.b.c:L:R} != "a.b"
.  error
.endif

.if ${a.b/c:L:R} != "a"
.  error
.endif

.if ${a:L:R} != "a"
.  error
.endif

.if ${a.a:L:R} != "a"
.  error
.endif

.if ${.gitignore:L:R} != ""
.  error
.endif

.if ${trailing/:L:R} != "trailing/"
.  error
.endif

all:
