# $NetBSD: Makefile,v 1.3 2003/07/17 21:27:11 grant Exp $

DISTNAME=	cn2jp1.4b
PKGNAME=	cn2jp-1.4b
WRKSRC=		${WRKDIR}/cn2jp
CATEGORIES=	converters
MASTER_SITES=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/
COMMENT=	library for code translation between Chinese and Japanese

USE_LIBTOOL=	yes
USE_GMAKE=	yes

NO_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/lib/jp-util.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lang-util.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
