# $NetBSD: Makefile,v 1.7 2005/06/14 16:38:17 minskim Exp $
#

DISTNAME=	xroach
PKGNAME=	${DISTNAME}-4.4
CATEGORIES=	x11 games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/games/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Cockroaches hide under your windows

DIST_SUBDIR=	xroach-4.4
DECOMPRESS_CMD=	${CAT}
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE} \
		MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}
MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
