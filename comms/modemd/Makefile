# $NetBSD: Makefile,v 1.10 2002/11/14 23:57:00 jlam Exp $

DISTNAME=	modemd-970221
PKGNAME=	modemd-19970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@netbsd.org
COMMENT=	Replacement getty for dialup ttys and a modem server

USE_BUILDLINK2=		# defined
MANCOMPRESSED_IF_MANZ=	# defined

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
