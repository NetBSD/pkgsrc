# $NetBSD: Makefile,v 1.9 2004/01/25 20:27:40 wiz Exp $
#

DISTNAME=	baekmuk-ttf-2.1
PKGREVISION=	2
CATEGORIES=	fonts korean
MASTER_SITES=	ftp://ftp.mizi.com/pub/baekmuk/

MAINTAINER=	junyoung@NetBSD.org
HOMEPAGE=	http://www.mizi.com/ko/prod/desktop/mizios/mos-pro2.htm
COMMENT=	Baekmuk family Korean TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/baekmuk-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	cd ${WRKDIR} && ${PAX} -rw -pm *.ttf ${FONTS_TTF_DIRS}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${FILESDIR}/COPYRIGHT ${DOCDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
