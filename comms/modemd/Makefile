# $NetBSD: Makefile,v 1.9 2001/08/19 04:48:36 jlam Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@netbsd.org
COMMENT=	Replacement getty for dialup ttys and a modem server

USE_BUILDLINK_ONLY=	yes
MANCOMPRESSED_IF_MANZ=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
