# $NetBSD: Makefile,v 1.197 2025/10/05 19:26:14 js Exp $

DISTNAME=	cups-filters-2.0.1
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_PROJECT=	cups-filters
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.linuxfoundation.org/openprinting/cups-filters
COMMENT=	Backends, filters, and other software for cups
LICENSE=	apache-2.0 # with gnu-gpl-v2 and gnu-lgpl-v2 exception

# https://github.com/OpenPrinting/cups-filters/issues/411
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

# qpdf's include/qpdf/QPDF.hh uses std::string_view
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_LIBTOOL=		yes
USE_TOOLS+=		bash:run pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-mutool
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-apple-raster-filter=rastertopdf
CONFIGURE_ARGS+=	--with-gs-path=${PREFIX}/bin/gs
CONFIGURE_ARGS+=	--with-pdftops-path=${PREFIX}/bin/pdftops
CONFIGURE_ARGS+=	--with-shell=${TOOLS_PATH.bash}

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/libcupsfilters/buildlink3.mk"
.include "../../print/libppd/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
