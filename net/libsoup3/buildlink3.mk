# $NetBSD: buildlink3.mk,v 1.5 2024/11/01 00:53:10 wiz Exp $

BUILDLINK_TREE+=	libsoup3

.if !defined(LIBSOUP3_BUILDLINK3_MK)
LIBSOUP3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsoup3+=	libsoup3>=3.2.2
BUILDLINK_ABI_DEPENDS.libsoup3?=		libsoup3>=3.4.4nb4
BUILDLINK_PKGSRCDIR.libsoup3?=		../../net/libsoup3

pkgbase := libsoup3
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libsoup3:Mgssapi}
.include "../../mk/krb5.buildlink3.mk"
.endif

.include "../../archivers/brotli/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/libpsl/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.endif	# LIBSOUP3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsoup3
