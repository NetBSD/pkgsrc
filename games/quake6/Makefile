# $NetBSD: Makefile,v 1.40 2015/04/25 14:23:03 tnn Exp $

DISTNAME=	quake-v6-bsd-kame
PKGNAME=	quake6-0.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.viagenie.qc.ca/quake/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.viagenie.qc.ca/en/ipv6-quake.shtml
COMMENT=	Quake over IPv6

DEPENDS+=	quakedata-[0-9]*:../../games/quakedata

WRKSRC=		${WRKDIR}/quakeforge

post-extract:
	cd ${WRKSRC}; ${FIND} . -name \*.o -exec ${RM} {} \;
	cd ${WRKSRC}; ${RM} config.cache

USE_TOOLS+=	gmake
USE_FEATURES=	inet6
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=	--disable-asmopt --bindir=/bin

BUILDLINK_DEPMETHOD.libXt?=	build

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${X11BASE:Q}/include
.endif

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
