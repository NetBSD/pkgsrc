# $NetBSD: buildlink3.mk,v 1.1 2018/08/05 17:59:55 nia Exp $

BUILDLINK_TREE+=	flite

.if !defined(FLITE_BUILDLINK3_MK)
FLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flite+=	flite>=1.3nb3
BUILDLINK_PKGSRCDIR.flite?=	../../audio/flite
.endif	# FLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-flite
