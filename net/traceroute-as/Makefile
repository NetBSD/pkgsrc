# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 22:40:11 seb Exp $
#

DISTNAME=	traceroute_991603.tar
PKGNAME=	traceroute-as-991603
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/
EXTRACT_SUFX=	.Z

MAINTAINER=	seb@netbsd.org
COMMENT=	Traceroute capable of reporting the AS number of hops

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PKG_SYSDEFS=	-DSYSV
PKG_LIBRARIES=	-lresolv -lsocket -lnsl
.endif

MAKE_FLAGS+=	CC=${CC:Q} PKG_CFLAGS=${CFLAGS:Q} PKG_SYSDEFS=${PKG_SYSDEFS:Q}
MAKE_FLAGS+=	PKG_LIBRARIES=${PKG_LIBRARIES:Q}
INSTALL_PROGRAM_SUID= ${INSTALL} ${COPY} ${STRIPFLAG} -o ${BINOWN} -g ${BINGRP} -m 4555
MAKE_ENV+=	BSD_INSTALL_PROGRAM_SUID="${INSTALL_PROGRAM_SUID}"

.include "../../mk/bsd.pkg.mk"
