# $NetBSD: Makefile,v 1.2 1998/07/30 22:48:20 tron Exp $

DISTNAME=		imaze1.3
PKGNAME=		imaze-1.3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTFILES=		imaze-sounds.tar imaze1.3.tar.Z

MAINTAINER=		root@garbled.net

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
