# $NetBSD: Makefile,v 1.6 2006/06/26 06:29:25 rillig Exp $

DISTNAME=		kyopon-0.3
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		itohy@NetBSD.org
#HOMEPAGE=
COMMENT=		tool to manipulate data of Kyocera AIR-EDGE PHONE

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

MAKE_FLAGS+=		BINDIR="${PREFIX}/bin"
MAKE_FLAGS+=		MANDIR="${PREFIX}/man"
MAKE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=		MANOWN=${MANOWN} MANGRP=${MANGRP}

pre-install:
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/cat1

.include "../../mk/bsd.pkg.mk"
