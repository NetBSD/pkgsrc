# $NetBSD: Makefile,v 1.20 2005/06/17 04:49:48 jlam Exp $

DISTNAME=	hpijs-1.7.1
PKGREVISION=	# empty
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.01nb4 ghostscript-nox11<=6.01nb4

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		# defined
CPPFLAGS+=		-DAPDK_BUFFER_SEND

PKGSRC_USE_TOOLS+=	gzip
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

.include "../../mk/bsd.pkg.mk"
