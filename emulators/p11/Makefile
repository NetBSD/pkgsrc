# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:45:35 jlam Exp $
#

DISTNAME=	p11-2.10a
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/cats/usr/harti/p11/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	PDP11 emulator

DEPENDS+=	libbegemot-[0-9]*:../../devel/libbegemot

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-begemot=${PREFIX}
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		yes

# override MAKEFLAGS in the build and install stages
do-build:
	cd ${WRKSRC} && ${GMAKE} ${ALL_TARGET} MAKEFLAGS=

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET} MAKEFLAGS=

.include "../../mk/bsd.pkg.mk"
