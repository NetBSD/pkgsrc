# $NetBSD: Makefile,v 1.1.1.1 2012/01/08 16:20:08 wiz Exp $
#

DISTNAME=	EB-Garamond-0.012
CATEGORIES=	fonts
MASTER_SITES=	# https://github.com/georgd/EB-Garamond/tarball/0.012

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.georgduffner.at/ebgaramond/index.html
COMMENT=	Egenolff-Berner Garamond font
LICENSE=	open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/georgd-EB-Garamond-d9f3abd

INSTALLATION_DIRS=	lib/X11/fonts/OTF
FONTS_DIRS.ttf=		lib/X11/fonts/OTF

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/otf/* ${DESTDIR}${PREFIX}/lib/X11/fonts/OTF

.include "../../mk/bsd.pkg.mk"
