# $NetBSD: Makefile,v 1.6 2003/09/22 09:11:31 wiz Exp $
#

DISTNAME=	cksfv-1.3
PKGREVISION=	1
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
