# $NetBSD: Makefile,v 1.16 2003/04/10 20:10:17 grant Exp $

DISTNAME=		imaze1.3
PKGNAME=		imaze-1.3
WRKSRC=			${WRKDIR}/imaze
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
DISTFILES=		imaze-sounds.tar imaze1.3.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://home.tu-clausthal.de/student/iMaze/
COMMENT=		Multiplayer, networked, action,x 3D maze game

EXTRACT_ONLY=		imaze1.3.tar.Z

USE_BUILDLINK2=		yes
USE_X11BASE=		yes

post-build:
	cd ${WRKSRC} && ${PAX} -O -rf ${DISTDIR}/imaze-sounds.tar

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
