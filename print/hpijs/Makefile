# $NetBSD: Makefile,v 1.15 2004/06/27 13:34:24 grant Exp $

DISTNAME=	hpijs-1.5
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.01nb4 ghostscript-nox11<=6.01nb4

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		# defined
CPPFLAGS+=		-DAPDK_BUFFER_SEND

ONLY_FOR_COMPILER=	gcc

do-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/ppd
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/html/hpijs
	cd ${WRKSRC} && ${CP} hpijs ${LOCALBASE}/bin/hpijs
	cd ${WRKSRC} && ${CP} hpijs_readme.html gs_hpijs.png \
		 ${LOCALBASE}/share/doc/html/hpijs/
	cd ${WRKSRC} && ${CP} ppd/HP* ${LOCALBASE}/share/ppd/
	${GZIP_CMD} ${LOCALBASE}/share/ppd/HP*.ppd

.include "../../mk/bsd.pkg.mk"
