# $NetBSD: hacks.mk,v 1.3 2008/02/05 22:03:57 tnn Exp $

# gcc 2.95 does not understand -Wfloat-equal
BUILDLINK_TRANSFORM+=	rm:-Wfloat-equal
