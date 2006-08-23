# $NetBSD: hacks.mk,v 1.1 2006/08/23 09:44:27 jmmv Exp $

# gcc 2.95 does not understand -Wfloat-equal
BUILDLINK_TRANSFORM+=	rm:-Wfloat-equal
