# $NetBSD: Makefile,v 1.14 2000/08/21 09:24:03 tron Exp $
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# 

DISTNAME=	xpdf-0.91
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/

DEPENDS+=	freetype-1.3.1:../../graphics/freetype
DEPENDS+=	ghostscript-fonts-*:../../print/ghostscript-fonts
DEPENDS+=	t1lib-1.0.1:../../textproc/t1lib
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	xpdf-crypto-*

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--enable-japanese --enable-chinese
CONFIGURE_ARGS+=--with-freetype-includes=${LOCALBASE}/include

post-install:
	${SED} 's|@@LOCALBASE@@|${LOCALBASE}|' \
		< ${FILESDIR}/xpdf-app-defaults \
		> ${X11BASE}/lib/X11/app-defaults/Xpdf

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+= --enable-a4-paper
.endif

.include "../../mk/bsd.pkg.mk"
