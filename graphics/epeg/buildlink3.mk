# $NetBSD: buildlink3.mk,v 1.9 2010/01/18 09:58:58 wiz Exp $

BUILDLINK_TREE+=	epeg

.if !defined(EPEG_BUILDLINK3_MK)
EPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.epeg+=	epeg>=0.9.0
BUILDLINK_ABI_DEPENDS.epeg?=	epeg>=0.9.0nb3
BUILDLINK_PKGSRCDIR.epeg?=	../../graphics/epeg

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # EPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-epeg
