# $NetBSD: buildlink3.mk,v 1.3 2025/12/16 22:46:05 wiz Exp $

BUILDLINK_TREE+=	libxspf

.if !defined(LIBXSPF_BUILDLINK3_MK)
LIBXSPF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxspf+=	libxspf>=1.2.0
BUILDLINK_PKGSRCDIR.libxspf?=	../../audio/libxspf

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.endif	# LIBXSPF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxspf
