# $NetBSD: Makefile,v 1.84 2024/05/16 06:15:10 wiz Exp $

DISTNAME=		bibletime-3.0.3
PKGREVISION=		16
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=bibletime/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz
EXTRACT_USING=		bsdtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bibletime.info/
COMMENT=		Bible study program based on SWORD and QT
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		pkg-config

DEPENDS+=		dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
TOOL_DEPENDS+=		po4a-[0-9]*:../../textproc/po4a
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

CMAKE_ARGS+=		-DBUILD_HANDBOOK_PDF=OFF
CMAKE_ARGS+=		-DBUILD_HOWTO_PDF=OFF
CMAKE_ARGS+=		-DBT_DOCBOOK_XSL_HTML_CHUNK_XSL:PATH="${PREFIX}/share/xsl/docbook/html/chunk.xsl"
CMAKE_ARGS+=		-DBT_RUNTIME_DOCDIR="${PREFIX}/share/doc/bibletime"

# macs need this to install correctly
CMAKE_ARGS+=		-DBT_BINDIR:PATH=${PREFIX}/bin
CMAKE_ARGS+=		-DBT_DATAROOTDIR:PATH=${PREFIX}/share
CMAKE_ARGS+=		-DBT_DATADIR:PATH=${PREFIX}/share

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/sword/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
