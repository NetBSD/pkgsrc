# $NetBSD: Makefile,v 1.8 2026/02/19 16:56:26 wiz Exp $

DISTNAME=	libxmlb-0.3.25
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/libxmlb
COMMENT=	Library to help create and query binary XML blobs
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/xmlb.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "options.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
