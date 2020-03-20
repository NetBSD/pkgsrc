# $NetBSD: Makefile,v 1.34 2020/03/20 11:58:14 nia Exp $

DISTNAME=	hpijs-2.1.4
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.01nb4
CONFLICTS+=	ghostscript-nox11<=6.01nb4

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CPPFLAGS+=	-DAPDK_BUFFER_SEND
USE_TOOLS+=	gzip
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpijs ${DESTDIR}${PREFIX}/bin/hpijs
	cd ${WRKSRC} && ${INSTALL_DATA} hpijs_readme.html gs_hpijs.png \
		 ${DESTDIR}${PREFIX}/share/doc/hpijs/
	${INSTALL_DATA} ${WRKSRC}/ppd/HP* ${DESTDIR}${PREFIX}/share/ppd/
	${GZIP_CMD} ${DESTDIR}${PREFIX}/share/ppd/HP*.ppd

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
