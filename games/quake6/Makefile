# $NetBSD: Makefile,v 1.22 2003/11/30 22:58:41 jschauma Exp $

DISTNAME=	quake-v6-bsd-kame
PKGNAME=	quake6-0.0
PKGREVISION=	1
WRKSRC=		${WRKDIR}/quakeforge
CATEGORIES=	games
MASTER_SITES=	http://www.viagenie.qc.ca/quake/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.viagenie.qc.ca/en/ipv6-quake.shtml
COMMENT=	Quake over IPv6

DEPENDS=	quakedata-[0-9]*:../../games/quakedata

USE_BUILDLINK2=	yes
USE_X11=	yes

post-extract:
	cd ${WRKSRC}; ${FIND} . -name \*.o -exec ${RM} {} \;
	cd ${WRKSRC}; ${RM} config.cache

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# This pkg can be built on USE_INET6 platform only
BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if !(defined(USE_INET6) && ${USE_INET6} == "YES")
PKG_FAIL_REASON= "${PKGNAME} requires IPv6 support"
.endif

# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=--disable-asmopt --bindir=/bin

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
