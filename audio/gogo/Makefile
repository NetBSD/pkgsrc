# $NetBSD: Makefile,v 1.1.1.1 2000/08/13 19:01:53 wiz Exp $
#

DISTNAME=		gogo235
PKGNAME=		gogo-2.35
CATEGORIES=		audio
MASTER_SITES=		http://homepage1.nifty.com/herumi/soft/gogo2/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		uebs@gmx.at
HOMEPAGE=		http://homepage1.nifty.com/herumi/gogo_e.html

BUILD_DEPENDS+=		nasm:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

USE_GMAKE=		YES
MIRROR_DISTFILE=	NO
LICENSE=		fee-based-commercial-use

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gogo
	@ ${INSTALL_DATA} ${WRKSRC}/readme*.txt ${PREFIX}/share/doc/gogo

.include "../../mk/bsd.pkg.mk"

.if (${OBJECT_FMT} == "a.out")
MAKE_FLAGS+=	ASFLAGS="-f aoutb -D__unix__ -DAOUT ${E3DN}"
.else
MAKE_FLAGS+=	ASFLAGS="-f elf -D__unix__ ${E3DN}"
.endif
