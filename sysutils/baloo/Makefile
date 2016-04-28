# $NetBSD: Makefile,v 1.6 2016/04/28 07:01:13 markd Exp $

DISTNAME=	baloo-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	sysutils
COMMENT=	KDE framework for searching and managing user metadata
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	polkit
.if ${OPSYS} != "Darwin"
PLIST.polkit=	yes
.endif

DEPENDS+=	libbaloo4-[0-9]*:../../sysutils/libbaloo4

PATCHDIR=	${.CURDIR}/../../sysutils/libbaloo4/patches
DISTINFO_FILE=	${.CURDIR}/../../sysutils/libbaloo4/distinfo

INSTALL_DIRS=	_KDE_build/icons _KDE_build/src/tools _KDE_build/src/file _KDE_build/src/pim

.include "../../devel/qjson/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
