# $NetBSD: buildlink3.mk,v 1.1 2019/01/30 12:55:13 leot Exp $

BUILDLINK_TREE+=	libxlsxwriter

.if !defined(LIBXLSXWRITER_BUILDLINK3_MK)
LIBXLSXWRITER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxlsxwriter+=	libxlsxwriter>=0.8.4
BUILDLINK_PKGSRCDIR.libxlsxwriter?=	../../textproc/libxlsxwriter

.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBXLSXWRITER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxlsxwriter
