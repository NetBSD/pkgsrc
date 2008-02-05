# $NetBSD: hacks.mk,v 1.2 2008/02/05 22:03:02 tnn Exp $

# gcc 2.95 does not understand -Wfloat-equal
BUILDLINK_TRANSFORM+=	rm:-Wfloat-equal
#XXX_DISABLED=yes
