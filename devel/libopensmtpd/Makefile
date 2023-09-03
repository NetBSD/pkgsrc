# $NetBSD: Makefile,v 1.2 2023/09/03 10:07:33 vins Exp $

DISTNAME=	libopensmtpd-0.7
CATEGORIES=	devel mail
MASTER_SITES=	https://distfiles.sigtrap.nl/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://distfiles.sigtrap.nl/
COMMENT=	Library for creating opensmtpd filters
LICENSE=	isc

USE_TOOLS+=	gmake

CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE   # strtonum()

MAKE_FILE=		Makefile.gnu
MAKE_ENV+=		LOCALBASE=${PREFIX:Q}
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man3
MAKE_ENV+=		MANFORMAT=man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "OpenBSD"
.  if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} >= 051100
MAKE_ENV+=	NEED_RECALLOCARRAY=0
.  else
MAKE_ENV+=	NEED_RECALLOCARRAY=1
.  endif
.endif

MAKE_ENV.NetBSD+=	NEED_EXPLICIT_BZERO=1
MAKE_ENV.Darwin+=	NEED_STRTONUM=1
MAKE_ENV.Linux+=	NEED_STRLCAT=1
MAKE_ENV.Linux+=	NEED_STRLCPY=1
MAKE_ENV.Linux+=	NEED_STRTONUM=1

INSTALL_ENV=		INSTALL=${INSTALL:Q} LINK=${LN:Q}
INSTALLATION_DIRS+=	include lib ${PKGMANDIR}/man3

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
