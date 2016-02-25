# $NetBSD: hacks.mk,v 1.2 2016/02/25 10:15:45 jperkin Exp $

# gcc in MirBSD does not recognize these options
BUILDLINK_TRANSFORM.MirBSD+=	rm:-fvisibility=hidden rm:-fvisibility-inlines-hidden
