# $NetBSD: Makefile,v 1.30 2012/10/08 13:45:39 asau Exp $

DISTNAME=	hpijs-2.1.4
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.01nb4 ghostscript-nox11<=6.01nb4

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CPPFLAGS+=		-DAPDK_BUFFER_SEND

USE_TOOLS+=		gzip
ONLY_FOR_COMPILER=	gcc
INSTALLATION_DIRS=	bin share/ppd share/doc/html/hpijs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${DESTDIR}${PREFIX}/bin/hpijs
	cd ${WRKSRC} && ${INSTALL_DATA} hpijs_readme.html gs_hpijs.png \
		 ${DESTDIR}${PREFIX}/share/doc/html/hpijs/
	${INSTALL_DATA} ${WRKSRC}/ppd/HP* ${DESTDIR}${PREFIX}/share/ppd/
	${GZIP_CMD} ${DESTDIR}${PREFIX}/share/ppd/HP*.ppd

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
