# $NetBSD: Makefile,v 1.1.1.1 2002/03/30 06:03:39 uebayasi Exp $

DISTNAME=	cn2jp1.4b
PKGNAME=	cn2jp-1.4b
CATEGORIES=	converters
MASTER_SITES=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/
COMMENT=	library for code translation between Chinese and Japanese

USE_LIBTOOL=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/cn2jp
NO_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/lib/jp-util.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lang-util.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
