# $NetBSD: Makefile,v 1.7 2005/04/05 11:14:15 wiz Exp $
#

DISTNAME=	p11-2.10a
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/cats/usr/harti/p11/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	PDP11 emulator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-begemot=${PREFIX}
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make

# override MAKEFLAGS in the build and install stages
do-build:
	cd ${WRKSRC} && ${GMAKE} ${BUILD_TARGET} MAKEFLAGS=

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET} MAKEFLAGS=

.include "../../devel/libbegemot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
