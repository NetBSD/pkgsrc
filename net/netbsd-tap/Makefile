# $NetBSD: Makefile,v 1.3 2005/02/20 21:50:57 cube Exp $

DISTNAME=	netbsd-tap-20050220
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cube@NetBSD.org
COMMENT=	NetBSD kernel module for virtual Ethernet devices

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
INSTALL_TARGET=	includes install

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*
INSTALLATION_DIRS=	lkm

.include "options.mk"

SUBST_CLASSES+=	tap_postinstall
SUBST_STAGE.tap_postinstall=	post-build
SUBST_FILES.tap_postinstall=	tap_postinstall.sh
SUBST_SED.tap_postinstall=	-e s,@SH@,${SH:Q},

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
