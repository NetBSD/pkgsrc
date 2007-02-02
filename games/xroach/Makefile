# $NetBSD: Makefile,v 1.12 2007/02/02 18:04:52 joerg Exp $
#

DISTNAME=	xroach
PKGNAME=	${DISTNAME}-4.4
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/games/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cockroaches hide under your windows

DIST_SUBDIR=	xroach-4.4
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} BINMODE=${BINMODE:Q} \
		MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q} MANMODE=${MANMODE:Q}
MANCOMPRESSED_IF_MANZ=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
