# $NetBSD: Makefile,v 1.24 2006/01/29 01:51:23 gavan Exp $

DISTNAME=	hpijs-2.1.4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.01nb4 ghostscript-nox11<=6.01nb4

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CPPFLAGS+=		-DAPDK_BUFFER_SEND

USE_TOOLS+=		gzip
ONLY_FOR_COMPILER=	gcc
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ppd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hpijs
	cd ${WRKSRC} && ${CP} hpijs ${PREFIX}/bin/hpijs
	cd ${WRKSRC} && ${CP} hpijs_readme.html gs_hpijs.png \
		 ${PREFIX}/share/doc/html/hpijs/
	cd ${WRKSRC} && ${CP} ppd/HP* ${PREFIX}/share/ppd/
	${GZIP_CMD} ${PREFIX}/share/ppd/HP*.ppd

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
