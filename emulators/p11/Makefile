# $NetBSD: Makefile,v 1.4 2004/01/22 08:36:04 grant Exp $
#

DISTNAME=	p11-2.10a
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/cats/usr/harti/p11/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	PDP11 emulator

DEPENDS+=	libbegemot-[0-9]*:../../devel/libbegemot

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-begemot=${PREFIX}
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GNU_TOOLS+=		make

# override MAKEFLAGS in the build and install stages
do-build:
	cd ${WRKSRC} && ${GMAKE} ${ALL_TARGET} MAKEFLAGS=

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET} MAKEFLAGS=

.include "../../mk/bsd.pkg.mk"
