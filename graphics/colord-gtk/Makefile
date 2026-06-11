# $NetBSD: Makefile,v 1.24 2026/06/11 07:17:04 wiz Exp $

DISTNAME=	colord-gtk-0.3.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Manage color profiles to accurately color input/output devices
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=		docbook-xsl-ns-[0-9]*:../../textproc/docbook-xsl-ns

USE_TOOLS+=		pkg-config xgettext

USE_PKGLOCALEDIR=	yes

PYTHON_FOR_BUILD_ONLY=	tool

DOCBOOK_MANPAGE_XSL=	${PREFIX}/share/xsl/docbook-ns/manpages/docbook.xsl

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	man/meson.build
SUBST_VARS.man+=	DOCBOOK_MANPAGE_XSL

.include "options.mk"

PKGCONFIG_OVERRIDE_STAGE=	pre-install

.include "../../devel/meson/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/colord/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../mk/bsd.pkg.mk"
