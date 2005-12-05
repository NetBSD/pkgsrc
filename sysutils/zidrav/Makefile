# $NetBSD: Makefile,v 1.2 2005/12/05 20:51:02 rillig Exp $
#

DISTNAME=	zidrav4unix-1.2.0
PKGNAME=	zidrav-1.20
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zidrav/}

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://sourceforge.net/projects/zidrav
COMMENT=	File corruption detection and repair program

USE_LANGUAGES=  c c++
BUILD_TARGET=	zidrav

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CXXFLAGS+=	-DCPU_BIGENDIAN
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${PREFIX}/bin/zidrav
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 ${PREFIX}/man/man1/zidrav.1

.include "../../mk/bsd.pkg.mk"
