# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:09 gutteridge Exp $

PKGREVISION= 4
.include "../../net/ettercap/Makefile.common"

PKGNAME=	${DISTNAME:S/ettercap-/ettercap-gtk-/1}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks (with GTK GUI)

CONFLICTS+=	ettercap-[0-9]*

CMAKE_ARGS+=	-DGTK_BUILD_TYPE=GTK3
CMAKE_ARGS+=	-DENABLE_GTK=ON

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
