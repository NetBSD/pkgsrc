# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:38 jlam Exp $
#

DISTNAME=		gogo239b
PKGNAME=		gogo-2.39.1
CATEGORIES=		audio
MASTER_SITES=		http://homepage1.nifty.com/herumi/soft/gogo2/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://homepage1.nifty.com/herumi/gogo_e.html
COMMENT=		Very fast lame-based mp3 encoder, i386 only

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

USE_TOOLS+=		gmake

RESTRICTED=		'Source based on patent protected Fraunhofer code'
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
LICENSE=		fee-based-commercial-use

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == "a.out")
MAKE_FLAGS+=	ASFLAGS="-f aoutb -D__unix__ -DAOUT ${E3DN}"
.else
MAKE_FLAGS+=	ASFLAGS="-f elf -D__unix__ ${E3DN}"
.endif

INSTALLATION_DIRS=	bin

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gogo
	@ ${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/gogo

.include "../../mk/bsd.pkg.mk"
