# $NetBSD: Makefile,v 1.7 2004/10/03 00:13:17 tv Exp $

DISTNAME=	cn2jp1.4b
PKGNAME=	cn2jp-1.4b
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/
COMMENT=	Library for code translation between Chinese and Japanese

WRKSRC=		${WRKDIR}/cn2jp
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make

NO_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cn2jp
	${INSTALL_DATA} ${WRKSRC}/lib/jp-util.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/lang-util.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
