# $NetBSD: Makefile,v 1.11 2016/02/25 16:20:53 jperkin Exp $
#

DISTNAME=	traceroute_991603.tar
PKGNAME=	traceroute-as-991603
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Traceroute capable of reporting the AS number of hops

WRKSRC=		${WRKDIR}

OPSYSVARS+=		PKG_LIBRARIES PKG_SYSDEFS
PKG_LIBRARIES.SunOS=	-lresolv -lsocket -lnsl
PKG_LIBRARIES.*=	# empty
PKG_SYSDEFS.SunOS=	-DSYSV
PKG_SYSDEFS.*=		#empty

MAKE_FLAGS+=	CC=${CC:Q} PKG_CFLAGS=${CFLAGS:M*:Q} PKG_SYSDEFS=${PKG_SYSDEFS:Q}
MAKE_FLAGS+=	PKG_LIBRARIES=${PKG_LIBRARIES:Q}
INSTALL_PROGRAM_SUID= ${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 4555
MAKE_ENV+=	BSD_INSTALL_PROGRAM_SUID=${INSTALL_PROGRAM_SUID:Q}

.include "../../mk/bsd.pkg.mk"
