# $NetBSD: buildlink3.mk,v 1.2 2013/03/17 14:43:48 asau Exp $

BUILDLINK_TREE+=	openpa

.if !defined(OPENPA_BUILDLINK3_MK)
OPENPA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openpa+=	openpa>=1.0.1
BUILDLINK_PKGSRCDIR.openpa?=	../../parallel/openpa
.endif	# OPENPA_BUILDLINK3_MK

BUILDLINK_TREE+=	-openpa
