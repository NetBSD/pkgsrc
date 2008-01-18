# $NetBSD: Makefile,v 1.8 2008/01/18 14:40:19 itohy Exp $

DISTNAME=		kyopon-0.5
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		itohy@NetBSD.org
#HOMEPAGE=
COMMENT=		tool to manipulate data of Kyocera PHS handset

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

MAKE_FLAGS+=		BINDIR="${PREFIX}/bin"
MAKE_FLAGS+=		MANDIR="${PREFIX}/man"
MAKE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=		MANOWN=${MANOWN} MANGRP=${MANGRP}

pre-install:
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/cat1

.include "../../mk/bsd.pkg.mk"
