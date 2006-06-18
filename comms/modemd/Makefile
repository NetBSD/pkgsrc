# $NetBSD: Makefile,v 1.16 2006/06/18 11:43:54 rillig Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@NetBSD.org
COMMENT=	Replacement getty for dialup ttys and a modem server

MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
