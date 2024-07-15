# $NetBSD: deptgt-begin-fail.mk,v 1.1 2024/07/15 09:10:15 jperkin Exp $
#
# Test for a .BEGIN target whose command results in an error.
# This stops make immediately and does not build the main targets.

.BEGIN:
	false

all:
	: This is not made.
