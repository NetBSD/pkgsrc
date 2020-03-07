# $NetBSD: Makefile,v 1.16 2020/03/07 22:51:40 fcambus Exp $
#

DISTNAME=	pcf2bdf-1.06
CATEGORIES=	fonts graphics x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ganaware/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	https://github.com/ganaware/pcf2bdf
COMMENT=	Convert X font from PCF to BDF
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	Makefile.gcc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o pcf2bdf pcf2bdf.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pcf2bdf.1

.include "../../mk/bsd.pkg.mk"
