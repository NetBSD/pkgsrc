# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:55 jmmv Exp $
#

DISTNAME=	baekmuk-ttf-2.0
WRKSRC=		${WRKDIR}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	ftp://ftp.mizi.com/pub/baekmuk/

MAINTAINER=	junyoung@netbsd.org
HOMEPAGE=	http://www.mizi.com/ko/prod/desktop/mizios/mos-pro2.htm
COMMENT=	Baekmuk family Korean TrueType fonts

FONT_FILES=	batang.ttf dotum.ttf gulim.ttf hline.ttf

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
DOCDIR=		${PREFIX}/share/doc/baekmuk-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR}
	for f in ${FONT_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${FONTDIR}; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${FILESDIR}/COPYRIGHT ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
