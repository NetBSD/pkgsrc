# $NetBSD: Makefile,v 1.5 2003/07/21 17:01:13 martti Exp $
#

DISTNAME=	cksfv-1.3
CATEGORIES=	misc
MASTER_SITES=	http://www.fodder.org/cksfv/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.fodder.org/cksfv/
COMMENT=	Check and create simple file verification (SFV) listings

do-install:
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cksfv
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cksfv
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/cksfv ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
