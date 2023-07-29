# $NetBSD: Makefile,v 1.39 2023/07/29 02:23:12 markd Exp $

DISTNAME=	kdesu-${KF5VER}
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Integration with su for elevated privileges
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=	-lsocket -lnsl

SPECIAL_PERMS+=	${PREFIX}/libexec/kf5/kdesud ${REAL_ROOT_USER} nogroup 2555

.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
