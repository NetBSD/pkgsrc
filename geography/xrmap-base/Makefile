# $NetBSD: Makefile,v 1.12 2012/10/04 09:19:21 asau Exp $
#

DISTNAME=		xrmap-2.29
PKGNAME=		xrmap-base-2.29
PKGREVISION=		3
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Earth map viewer - base program

MAKE_JOBS_SAFE=		no

USE_IMAKE=		yes
MAKE_FLAGS+=		MANPATH=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	share/rmap/factbook

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
