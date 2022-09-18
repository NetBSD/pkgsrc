# $NetBSD: Makefile,v 1.8 2022/09/18 13:49:00 he Exp $
#

DISTNAME=	zidrav4unix-1.2.0
PKGNAME=	zidrav-1.20
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zidrav/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/zidrav
COMMENT=	File corruption detection and repair program

USE_LANGUAGES=	c c++
BUILD_TARGET=	zidrav

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CXXFLAGS+=	-DCPU_BIGENDIAN
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${DESTDIR}${PREFIX}/bin/zidrav
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/zidrav.1

.include "../../mk/bsd.pkg.mk"
