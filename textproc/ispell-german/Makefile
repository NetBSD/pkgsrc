# $NetBSD: Makefile,v 1.2 2002/07/27 19:05:54 jschauma Exp $
#

DISTNAME=	igerman98-20011124
PKGNAME=	ispell-german-20011124
CATEGORIES=	textproc
MASTER_SITES=	http://lisa.goe.net/~bjacke/igerman98/dict/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lisa.goe.net/~bjacke/igerman98/
COMMENT=	German dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20nb1:../../textproc/ispell-base

ALL_TARGET=	german.hash

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/german.aff ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/german.hash ${PREFIX}/lib
	(cd ${PREFIX}/lib && ${LN} -s german.aff deutsch.aff)
	(cd ${PREFIX}/lib && ${LN} -s german.hash deutsch.hash)

.include "../../mk/bsd.pkg.mk"
