# $NetBSD: Makefile,v 1.19 2004/10/03 00:14:45 tv Exp $

DISTNAME=		imaze1.3
PKGNAME=		imaze-1.3
PKGREVISION=	1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
DISTFILES=		imaze-sounds.tar imaze1.3.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://home.tu-clausthal.de/student/iMaze/
COMMENT=		Multiplayer, networked, action,x 3D maze game

EXTRACT_ONLY=		imaze1.3.tar.Z

WRKSRC=			${WRKDIR}/imaze
USE_BUILDLINK3=		yes
USE_X11BASE=		yes

post-build:
	cd ${WRKSRC} && ${PAX} -O -rf ${DISTDIR}/imaze-sounds.tar

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
