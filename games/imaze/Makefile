# $NetBSD: Makefile,v 1.7 2000/01/02 03:20:11 wiz Exp $

DISTNAME=		imaze1.3
PKGNAME=		imaze-1.3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
DISTFILES=		imaze-sounds.tar imaze1.3.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://home.tu-clausthal.de/student/iMaze/

EXTRACT_ONLY=		imaze1.3.tar.Z
WRKSRC=			${WRKDIR}/imaze

USE_MOTIF=		yes
USE_X11BASE=		yes

post-build:
	cd ${WRKSRC} && ${PAX} -rf ${DISTDIR}/imaze-sounds.tar

.include "../../mk/bsd.pkg.mk"
