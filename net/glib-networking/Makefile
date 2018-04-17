# $NetBSD: Makefile,v 1.33 2018/04/17 13:29:57 wiz Exp $

DISTNAME=	glib-networking-2.56.0
PKGREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glib-networking/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Network-related giomodules for glib
LICENSE=	gnu-lgpl-v2

MESON_ARGS+=	-Dca_certificates_path=/etc/openssl/certs/ca-certificates.crt
USE_TOOLS+=	pkg-config gmake gettext

REPLACE_PYTHON+=	find-ca-certificates
REPLACE_PYTHON+=	meson_post_install.py

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.56.0
.include "../../devel/glib2/modules.mk"
BUILDLINK_API_DEPENDS.libproxy+=	libproxy>=0.3.1
.include "../../www/libproxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.6.0nb1
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
