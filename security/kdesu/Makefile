# $NetBSD: Makefile,v 1.5 2017/04/22 21:03:16 adam Exp $

DISTNAME=	kdesu-${KF5VER}
PKGREVISION=	4
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Integration with su for elevated privileges
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

SPECIAL_PERMS+=	${PREFIX}/libexec/kf5/kdesud ${REAL_ROOT_USER} nogroup 2555

.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
