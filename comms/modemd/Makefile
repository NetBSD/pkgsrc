# $NetBSD: Makefile,v 1.12 2004/04/11 06:51:20 snj Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@NetBSD.org
COMMENT=	Replacement getty for dialup ttys and a modem server

USE_BUILDLINK3=		# defined
MANCOMPRESSED_IF_MANZ=	# defined

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
