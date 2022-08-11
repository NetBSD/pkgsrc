# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:14 gutteridge Exp $

DISTNAME=	dmenu-wld-4.6.0.20191014
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}
GITHUB_PROJECT=	dmenu
GITHUB_TAG=	f385d9d18813071b4b4257bf8d4d572daeda0e70

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/dmenu
COMMENT=	Dynamic menu for Wayland
LICENSE=	mit

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	PIXMANINC=${BUILDLINK_DIR}/include/pixman-1
MAKE_FLAGS+=	SWCPROTO=${PREFIX}/share/swc/swc.xml

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/dmenu ${DESTDIR}${PREFIX}/bin/dmenu-wld
	${MV} ${DESTDIR}${PREFIX}/bin/dmenu_run ${DESTDIR}${PREFIX}/bin/dmenu-wld_run
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dmenu.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dmenu-wld.1
	${RM} -f ${DESTDIR}${PREFIX}/bin/dmenu_path
	${RM} -f ${DESTDIR}${PREFIX}/bin/stest
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/stest.1

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/wld/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../wm/swc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
