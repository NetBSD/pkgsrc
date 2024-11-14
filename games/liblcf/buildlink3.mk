# $NetBSD: buildlink3.mk,v 1.13 2024/11/14 22:19:56 wiz Exp $

BUILDLINK_TREE+=	liblcf

.if !defined(LIBLCF_BUILDLINK3_MK)
LIBLCF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblcf+=	liblcf>=0.5.4
BUILDLINK_ABI_DEPENDS.liblcf?=	liblcf>=0.7.0nb8
BUILDLINK_PKGSRCDIR.liblcf?=	../../games/liblcf

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBLCF_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblcf
