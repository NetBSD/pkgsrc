# $NetBSD: Makefile,v 1.16 2002/01/24 12:21:35 skrll Exp $

DISTNAME=	quake-v6-bsd-kame
PKGNAME=	quake6-0.0
CATEGORIES=	games
MASTER_SITES=	http://www.viagenie.qc.ca/quake/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.viagenie.qc.ca/en/ipv6-quake.shtml
COMMENT=	Quake over IPv6

DEPENDS=	quakedata-[0-9]*:../../games/quakedata

WRKSRC=		${WRKDIR}/quakeforge

USE_BUILDLINK_ONLY=	yes

post-extract:
	cd ${WRKSRC}; ${FIND} . -name \*.o -exec ${RM} {} \;
	cd ${WRKSRC}; ${RM} config.cache

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# This pkg can be built on USE_INET6 platform only
BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if !(defined(USE_INET6) && ${USE_INET6} == "YES")
IGNORE=		"${PKGNAME} requires IPv6 support"
.endif

# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=--disable-asmopt --bindir=/bin

.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
