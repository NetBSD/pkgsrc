# $NetBSD: Makefile,v 1.3 1998/06/20 09:20:39 agc Exp $

DISTNAME=	modemd-970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@endicor.com

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

pre-install:
	${MKDIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
