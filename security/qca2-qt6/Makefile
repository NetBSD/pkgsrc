# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:19 adam Exp $

PKGNAME=	qca2-qt6-${DISTNAME:C/.*-//}
PKGREVISION=	1

COMMENT=	Cross-platform crypto API for Qt6

.include "../../security/qca2-qt5/Makefile.common"

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

INSTALLATION_DIRS=	lib/pkgconfig

CMAKE_ARGS+=	-DQT6=ON
CMAKE_ARGS+=	-DBUILD_PLUGINS=none
CMAKE_ARGS+=	-DQCA_MAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# qt6 insists on a UTF locale, override setting C in bsd.pkg.mk
ALL_ENV+=	LANG=C.UTF-8
ALL_ENV+=	LC_ALL=C.UTF-8
ALL_ENV+=	LC_COLLATE=C.UTF-8
ALL_ENV+=	LC_CTYPE=C.UTF-8
ALL_ENV+=	LC_MESSAGES=C.UTF-8
ALL_ENV+=	LC_MONETARY=C.UTF-8
ALL_ENV+=	LC_NUMERIC=C.UTF-8
ALL_ENV+=	LC_TIME=C.UTF-8
