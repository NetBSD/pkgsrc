# $NetBSD: Makefile,v 1.9 2002/07/19 12:43:51 wiz Exp $
# 

DISTNAME=	xpdf-1.00
PKGREVISION=	1		# because of switch to freetype2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Display tool for PDF files

DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

CONFLICTS=	xpdf-crypto-[0-9]*

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_FREETYPE2=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-freetype2-includes=${BUILDLINK_DIR}/include/freetype2
CONFIGURE_ARGS+=	--with-t1-includes=${BUILDLINK_DIR}/include
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=		SED="${SED}" ECHO="${ECHO}"

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

.include "../../fonts/t1lib/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
