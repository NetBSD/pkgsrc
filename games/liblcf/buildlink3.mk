# $NetBSD: buildlink3.mk,v 1.2 2019/04/03 00:32:43 ryoon Exp $

BUILDLINK_TREE+=	liblcf

.if !defined(LIBLCF_BUILDLINK3_MK)
LIBLCF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblcf+=	liblcf>=0.5.4
BUILDLINK_ABI_DEPENDS.liblcf?=	liblcf>=0.6.0nb1
BUILDLINK_PKGSRCDIR.liblcf?=	../../games/liblcf

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBLCF_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblcf
