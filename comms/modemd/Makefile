# $NetBSD: Makefile,v 1.2 1998/04/15 10:38:17 agc Exp $

DISTNAME=	modemd-970221
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.vix.com/pub/modemd/

MAINTAINER=	tsarna@endicor.com

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

pre-install:
	${MKDIR} ${PREFIX}/share/examples/modemd

.include "../../mk/bsd.pkg.mk"
