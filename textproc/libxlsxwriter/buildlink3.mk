# $NetBSD: buildlink3.mk,v 1.4 2019/12/30 12:35:42 sjmulder Exp $

BUILDLINK_TREE+=	libxlsxwriter

.if !defined(LIBXLSXWRITER_BUILDLINK3_MK)
LIBXLSXWRITER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxlsxwriter+=	libxlsxwriter>=0.9.1
BUILDLINK_PKGSRCDIR.libxlsxwriter?=	../../textproc/libxlsxwriter

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBXLSXWRITER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxlsxwriter
