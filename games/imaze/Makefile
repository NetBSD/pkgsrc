# $NetBSD: Makefile,v 1.5 1999/01/30 23:18:47 agc Exp $

DISTNAME=		imaze1.3
PKGNAME=		imaze-1.3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTFILES=		imaze-sounds.tar imaze1.3.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://home.tu-clausthal.de/student/iMaze/

EXTRACT_ONLY=		imaze1.3.tar.Z
WRKSRC=			${WRKDIR}/imaze

USE_MOTIF=		yes
USE_X11BASE=		yes

post-build:
	cd ${WRKSRC} && /bin/pax -rf ${DISTDIR}/imaze-sounds.tar

.include "../../mk/bsd.pkg.mk"
