# $NetBSD: Makefile,v 1.27 2001/09/27 23:18:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# 

DISTNAME=	xpdf-0.92
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Display tool for PDF files

DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

CONFLICTS=	xpdf-crypto-[0-9]*

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-japanese
CONFIGURE_ARGS+=	--enable-chinese
CONFIGURE_ARGS+=	--with-freetype-includes=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-t1-includes=${BUILDLINK_DIR}/include
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=		SED="${SED}" ECHO="${ECHO}"

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

post-install:
	${SED}	-e "s|@@LOCALBASE@@|${LOCALBASE}|g"			\
		${FILESDIR}/xpdf-app-defaults				\
		> ${X11PREFIX}/lib/X11/app-defaults/Xpdf

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../textproc/t1lib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
