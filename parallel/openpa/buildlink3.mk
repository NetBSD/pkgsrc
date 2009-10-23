# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/23 21:57:20 asau Exp $

BUILDLINK_TREE+=	openpa

.if !defined(OPENPA_BUILDLINK3_MK)
OPENPA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openpa+=	openpa>=1.0.1
BUILDLINK_PKGSRCDIR.openpa?=	../../parallel/openpa
BUILDLINK_DEPMETHOD.openpa?=	build
.endif	# OPENPA_BUILDLINK3_MK

BUILDLINK_TREE+=	-openpa
