# $NetBSD: Makefile,v 1.3 1998/08/20 15:16:55 tsarna Exp $

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
USE_X11=		yes

post-build:
	cd ${WRKSRC} && /bin/pax -rf ${DISTDIR}/imaze-sounds.tar

.include "../../mk/bsd.pkg.mk"
.if (${OBJECT_FMT} == "ELF")
RPATH=		-Wl,-rpath,${PREFIX}/lib
.endif
MAKE_ENV+=	RPATH=${RPATH}
