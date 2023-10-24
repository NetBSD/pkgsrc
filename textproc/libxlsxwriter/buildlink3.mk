# $NetBSD: buildlink3.mk,v 1.14 2023/10/24 22:11:19 wiz Exp $

BUILDLINK_TREE+=	libxlsxwriter

.if !defined(LIBXLSXWRITER_BUILDLINK3_MK)
LIBXLSXWRITER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxlsxwriter+=	libxlsxwriter>=1.1.4
BUILDLINK_ABI_DEPENDS.libxlsxwriter?=	libxlsxwriter>=1.1.5nb2
BUILDLINK_PKGSRCDIR.libxlsxwriter?=	../../textproc/libxlsxwriter

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif	# LIBXLSXWRITER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxlsxwriter
