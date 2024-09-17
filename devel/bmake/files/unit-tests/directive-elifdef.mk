# $NetBSD: directive-elifdef.mk,v 1.2 2024/09/17 11:52:31 jperkin Exp $
#
# Tests for the .elifdef directive, which is seldom used.  Instead of writing
# '.elifdef VAR', the usual form is the more general '.elif defined(VAR)'.

# At this point, VAR is not defined, so the condition evaluates to false.
.if 0
.elifdef VAR
.  error
.endif

VAR=	# defined

# At this point, VAR is defined, so the condition evaluates to true.
.if 0
.elifdef VAR
.else
.  error
.endif

all:
