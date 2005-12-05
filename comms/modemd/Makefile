# $NetBSD: Makefile,v 1.15 2005/12/05 20:49:55 rillig Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@NetBSD.org
COMMENT=	Replacement getty for dialup ttys and a modem server

MANCOMPRESSED_IF_MANZ=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
