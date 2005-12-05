# $NetBSD: Makefile,v 1.30 2005/12/05 20:50:17 rillig Exp $

DISTNAME=	quake-v6-bsd-kame
PKGNAME=	quake6-0.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.viagenie.qc.ca/quake/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.viagenie.qc.ca/en/ipv6-quake.shtml
COMMENT=	Quake over IPv6

DEPENDS+=	quakedata-[0-9]*:../../games/quakedata

WRKSRC=		${WRKDIR}/quakeforge

post-extract:
	cd ${WRKSRC}; ${FIND} . -name \*.o -exec ${RM} {} \;
	cd ${WRKSRC}; ${RM} config.cache

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

# This pkg can be built on USE_INET6 platform only
BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if !(defined(USE_INET6) && ${USE_INET6} == "YES")
PKG_FAIL_REASON+=	"${PKGNAME} requires IPv6 support"
.endif

# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=--disable-asmopt --bindir=/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
