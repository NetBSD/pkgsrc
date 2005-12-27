# $NetBSD: Makefile,v 1.7 2005/12/27 13:54:58 seb Exp $
#

DISTNAME=	traceroute_991603.tar
PKGNAME=	traceroute-as-991603
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/
EXTRACT_SUFX=	.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Traceroute capable of reporting the AS number of hops

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PKG_SYSDEFS=	-DSYSV
PKG_LIBRARIES=	-lresolv -lsocket -lnsl
.endif

MAKE_FLAGS+=	CC=${CC:Q} PKG_CFLAGS=${CFLAGS:M*:Q} PKG_SYSDEFS=${PKG_SYSDEFS:Q}
MAKE_FLAGS+=	PKG_LIBRARIES=${PKG_LIBRARIES:Q}
INSTALL_PROGRAM_SUID= ${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 4555
MAKE_ENV+=	BSD_INSTALL_PROGRAM_SUID=${INSTALL_PROGRAM_SUID:Q}

.include "../../mk/bsd.pkg.mk"
