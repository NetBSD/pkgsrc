# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:15 asau Exp $
#

DISTNAME=	EB-Garamond-0.012
CATEGORIES=	fonts
MASTER_SITES=	# https://github.com/georgd/EB-Garamond/tarball/0.012

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.georgduffner.at/ebgaramond/index.html
COMMENT=	Egenolff-Berner Garamond font
LICENSE=	open-font-license

WRKSRC=		${WRKDIR}/georgd-EB-Garamond-d9f3abd

INSTALLATION_DIRS=	lib/X11/fonts/OTF
FONTS_DIRS.ttf=		lib/X11/fonts/OTF

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/otf/* ${DESTDIR}${PREFIX}/lib/X11/fonts/OTF

.include "../../mk/bsd.pkg.mk"
