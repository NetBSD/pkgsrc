# $NetBSD: Makefile,v 1.4 1998/08/20 15:16:42 tsarna Exp $

DISTNAME=	modemd-970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@netbsd.org

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

pre-install:
	${MKDIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
