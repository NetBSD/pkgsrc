# $NetBSD: deptgt-begin-fail.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Test for a .BEGIN target whose command results in an error.
# This stops make immediately and does not build the main targets.

.BEGIN:
	false

all:
	: This is not made.
