# $NetBSD: Makefile,v 1.2 2001/02/17 18:08:54 wiz Exp $
#

DISTNAME=	cksfv-1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.fodder.org/cksfv/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.fodder.org/cksfv/
COMMENT=	check and create simple file verification (SFV) listings

do-install:
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cksfv
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cksfv
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/cksfv ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
