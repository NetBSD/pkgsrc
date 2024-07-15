# $NetBSD: varmod-to-title.mk,v 1.1 2024/07/15 09:10:31 jperkin Exp $
#
# Tests for the :tc variable modifier, which converts the expression value
# to lowercase.
#
# TODO: What about non-ASCII characters? ISO-8859-1, UTF-8?

.if ${:UUPPER:tt} != "Upper"
.  error
.endif

.if ${:Ulower:tt} != "Lower"
.  error
.endif

.if ${:UMixeD case.:tt} != "Mixed Case."
.  error
.endif

# The ':tt' modifier works on the whole string, without splitting it into
# words.
.if ${:Umultiple   spaces:tt} != "Multiple   Spaces"
.  error
.endif

# Note words only count if separated by spaces
.if ${:Uthis&that or os/2:tt} != "This&that Or Os/2"
.  error
.endif

all: .PHONY
