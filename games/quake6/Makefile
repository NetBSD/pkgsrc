# $NetBSD: Makefile,v 1.9 2001/02/05 09:00:56 tron Exp $

DISTNAME=	quake-v6-bsd-kame
PKGNAME=	quake6-0.0
CATEGORIES=	games
MASTER_SITES=	http://www.viagenie.qc.ca/quake/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	quake6-00-v6-20000202b.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.viagenie.qc.ca/en/ipv6-quake.shtml

DEPENDS=	quakedata-*:../../games/quakedata
BUILD_DEPENDS=	${LOCALBASE}/bin/autoremake:../../devel/autoconf

WRKSRC=		${WRKDIR}/quakeforge

post-extract:
	(cd ${WRKSRC}; ${FIND} . -name \*.o -exec ${RM} {} \;)
	(cd ${WRKSRC}; ${RM} config.cache)

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

# This pkg can be built on USE_INET6 platform only
BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if !(defined(USE_INET6) && ${USE_INET6} == "YES")
IGNORE=		"${PKGNAME} requires IPv6 support"
.endif

# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=--disable-asmopt --bindir=/bin

post-patch:
	(cd ${WRKSRC}; autoreconf)

.include "../../mk/bsd.pkg.mk"
