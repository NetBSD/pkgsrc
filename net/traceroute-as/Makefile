# $NetBSD: Makefile,v 1.15 2024/06/25 16:24:31 ryoon Exp $

DISTNAME=	traceroute_991603.tar
PKGNAME=	traceroute-as-991603
CATEGORIES=	net
#MASTER_SITES=	ftp://ftp.nikhef.nl/pub/network/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Traceroute capable of reporting the AS number of hops

WRKSRC=		${WRKDIR}

OPSYSVARS+=		PKG_LIBRARIES PKG_SYSDEFS
PKG_LIBRARIES.SunOS=	-lresolv -lsocket -lnsl
PKG_LIBRARIES.*=	# empty
PKG_SYSDEFS.SunOS=	-DSYSV
PKG_SYSDEFS.*=		#empty

MAKE_FLAGS+=		CC=${CC:Q} PKG_CFLAGS=${CFLAGS:M*:Q} PKG_SYSDEFS=${PKG_SYSDEFS:Q}
MAKE_FLAGS+=		PKG_LIBRARIES=${PKG_LIBRARIES:Q} DESTMAN=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		BINOWN=${BINOWN} BINGRP=${BINGRP}

INSTALLATION_DIRS+=	${PKGMANDIR}/man8 sbin

SPECIAL_PERMS+=		sbin/traceroute-as ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"
