# $NetBSD: Makefile,v 1.12 2020/01/26 17:30:42 rillig Exp $

DISTNAME=		goom-2k4-0-src
PKGNAME=		goom-2004.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=goom/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.fovea.cc/?page=details_produits&id=goom
COMMENT=		Visual effects generator for mp3 players
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/goom2k4-0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoom2.pc.in
GNU_CONFIGURE=		yes
GCC_REQD+=		3.3
USE_TOOLS+=		pkg-config

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
