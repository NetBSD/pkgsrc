# $NetBSD: Makefile,v 1.7 2001/02/16 13:56:18 wiz Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@netbsd.org
COMMENT=	Replacement getty for dialup ttys and a modem server

MANCOMPRESSED_IF_MANZ=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
