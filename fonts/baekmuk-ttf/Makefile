# $NetBSD: Makefile,v 1.6 2003/04/01 00:28:25 salo Exp $
#

DISTNAME=	baekmuk-ttf-2.1
WRKSRC=		${WRKDIR}
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
