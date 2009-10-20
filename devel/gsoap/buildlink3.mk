# $NetBSD: buildlink3.mk,v 1.1 2009/10/20 16:22:50 agc Exp $

BUILDLINK_TREE+=	gsoap

.if !defined(GSOAP_BUILDLINK3_MK)
GSOAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsoap+=	gsoap>=2.7.13
BUILDLINK_PKGSRCDIR.gsoap?=	../../devel/gsoap
.endif	# GSOAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsoap
