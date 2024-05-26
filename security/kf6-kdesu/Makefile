# $NetBSD: Makefile,v 1.1 2024/05/26 12:46:46 markd Exp $

DISTNAME=	kdesu-${KF6VER}
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Integration with su for elevated privileges
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=	-lsocket -lnsl

SPECIAL_PERMS+=	${PREFIX}/libexec/kf6/kdesud ${REAL_ROOT_USER} nogroup 2555

.include "../../devel/kf6-kpty/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
