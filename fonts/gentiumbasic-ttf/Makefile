# $NetBSD: Makefile,v 1.1 2023/03/28 13:48:22 joerg Exp $
#

DISTNAME=	GentiumBasic_1102
PKGNAME=	gentiumbasic-ttf-1.102
CATEGORIES=	fonts
MASTER_SITES=	https://software.sil.org/downloads/r/gentium/
EXTRACT_SUFX=	.zip

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://software.sil.org/gentium/
COMMENT=	Gentium subset with additional weights
LICENSE=	ofl-v1.1

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
