# $NetBSD: buildlink3.mk,v 1.9 2010/02/28 20:49:21 tonio Exp $

BUILDLINK_TREE+=	libsoup24

.if !defined(LIBSOUP24_BUILDLINK3_MK)
LIBSOUP24_BUILDLINK3_MK:=

# API 2.4.0 but 2.28.0 due to buildlink dependency change
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.28.0
BUILDLINK_ABI_DEPENDS.libsoup24?=	libsoup24>=2.26.0
BUILDLINK_PKGSRCDIR.libsoup24?=		../../net/libsoup24

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"

pkgbase := libsoup24
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libsoup24:Mgnome)
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.endif

.endif # LIBSOUP24_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsoup24
