# $NetBSD: Makefile,v 1.19 2009/06/30 00:07:11 joerg Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@NetBSD.org
COMMENT=	Replacement getty for dialup ttys and a modem server

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 \
			sbin share/examples/modemd

.include "../../mk/bsd.pkg.mk"
