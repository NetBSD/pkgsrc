# $NetBSD: Makefile,v 1.1 2026/09/29 16:06:19 bouyer Exp $

DISTNAME=	libspnav-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeSpacenav/}
GITHUB_PROJECT=	libspnav
GITHUB_RELEASE=	v1.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FreeSpacenav/libspnav/
COMMENT=	Spacenavd or 3dxsrv to get input from 6-dof devices
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	spnav.pc.in

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV}	share/pkgconfig lib/
	cd ${DESTDIR}${PREFIX} && ${RMDIR} share

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
