# $NetBSD: Makefile,v 1.17 2012/10/06 11:55:02 asau Exp $
#

DISTNAME=	xroach
PKGNAME=	${DISTNAME}-4.4
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/games/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cockroaches hide under your windows

USE_TOOLS+=		nroff
USE_BSD_MAKEFILE=	yes

DIST_SUBDIR=	xroach-4.4

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat6 ${PKGMANDIR}/man6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
