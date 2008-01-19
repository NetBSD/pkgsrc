# $NetBSD: Makefile,v 1.25 2008/01/19 09:16:21 wiz Exp $

DISTNAME=		imaze1.3
PKGNAME=		imaze-1.3
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
DISTFILES=		imaze-sounds.tar imaze1.3.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.tu-clausthal.de/student/iMaze/
COMMENT=		Multiplayer, networked, action,x 3D maze game

EXTRACT_ONLY=		imaze1.3.tar.Z

WRKSRC=			${WRKDIR}/imaze
USE_X11BASE=		yes

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man6

post-build:
	cd ${WRKSRC} && ${PAX} -O -rf ${DISTDIR}/imaze-sounds.tar

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
