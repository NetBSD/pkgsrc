# $NetBSD: Makefile,v 1.10 2012/10/23 17:19:14 asau Exp $
#

DISTNAME=	traceroute_991603.tar
PKGNAME=	traceroute-as-991603
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
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
