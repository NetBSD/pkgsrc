# $NetBSD: Makefile,v 1.1 2023/09/02 21:32:11 vins Exp $

DISTNAME=	libopensmtpd-0.7
CATEGORIES=	devel mail
MASTER_SITES=	https://distfiles.sigtrap.nl/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://distfiles.sigtrap.nl/
COMMENT=	Library for creating opensmtpd filters
LICENSE=	isc

USE_TOOLS+=	gmake

MAKE_FILE=		Makefile.gnu
MAKE_ENV+=		LOCALBASE=${PREFIX:Q}
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man3
MAKE_ENV+=		MANFORMAT=man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "OpenBSD" || ${OPSYS} != "SunOS"
MAKE_ENV+=	NEED_RECALLOCARRAY=1
.endif

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D_OPENBSD_SOURCE
MAKE_ENV+=	NEED_EXPLICIT_BZERO=1

.elif ${OPSYS} == "Linux"
MAKE_ENV+=	NEED_STRLCAT=1
MAKE_ENV+=	NEED_STRLCPY=1
MAKE_ENV+=	NEED_STRTONUM=1

.elif ${OPSYS} == "Darwin"
MAKE_ENV+=	NEED_STRTONUM=1
.endif

INSTALL_ENV=		INSTALL=${INSTALL:Q} LINK=${LN:Q}
INSTALLATION_DIRS+=	include lib ${PKGMANDIR}/man3

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
