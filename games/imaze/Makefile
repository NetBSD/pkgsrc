# $NetBSD: Makefile,v 1.1 1998/07/30 21:40:33 tron Exp $

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
	${EXTRACT_CMD} -xmf ${DISTDIR}/imaze-sounds.tar -C ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
.if (${OBJECT_FMT} == "ELF")
RPATH=		-Wl,-rpath,${PREFIX}/lib
.endif
MAKE_ENV+=	RPATH=${RPATH}
