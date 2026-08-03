# $NetBSD: Makefile,v 1.13 2026/08/03 17:21:42 wiz Exp $

DISTNAME=	libxmlb-0.3.29
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/libxmlb
COMMENT=	Library to help create and query binary XML blobs
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/xmlb.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "options.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.68
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
