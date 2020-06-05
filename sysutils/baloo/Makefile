# $NetBSD: Makefile,v 1.28 2020/06/05 12:49:15 jperkin Exp $

DISTNAME=	baloo-${_KDE_VERSION}
PKGREVISION=	24
CATEGORIES=	sysutils
COMMENT=	KDE framework for searching and managing user metadata
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		polkit
.if ${OPSYS} != "Darwin"
PLIST.polkit=		yes
INSTALLATION_DIRS+=	share/PolicyKit/policy
.endif
INSTALLATION_DIRS+=	share/dbus-1/interfaces share/dbus-1/system-services

DEPENDS+=	libbaloo4-[0-9]*:../../sysutils/libbaloo4

PATCHDIR=	${.CURDIR}/../../sysutils/libbaloo4/patches
DISTINFO_FILE=	${.CURDIR}/../../sysutils/libbaloo4/distinfo

INSTALL_DIRS=	_KDE_build/icons _KDE_build/src/tools _KDE_build/src/pim/agent

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_KDE_build/src/file/baloo_file ${DESTDIR}${PREFIX}/bin/baloo_file
	${INSTALL_PROGRAM} ${WRKSRC}/_KDE_build/src/file/cleaner/baloo_file_cleaner ${DESTDIR}${PREFIX}/bin/baloo_file_cleaner
	${INSTALL_PROGRAM} ${WRKSRC}/_KDE_build/src/file/extractor/baloo_file_extractor ${DESTDIR}${PREFIX}/bin/baloo_file_extractor
	${INSTALL_DATA} ${WRKSRC}/src/file/org.kde.baloo.file.indexer.xml ${DESTDIR}${PREFIX}/share/dbus-1/interfaces/org.kde.baloo.file.indexer.xml
	${INSTALL_DATA} ${WRKSRC}/_KDE_build/src/file/inotify/org.kde.baloo.filewatch.service ${DESTDIR}${PREFIX}/share/dbus-1/system-services/org.kde.baloo.filewatch.service
.if ${OPSYS} != "Darwin"
	${INSTALL_DATA} ${WRKSRC}/_KDE_build/src/file/inotify/org.kde.baloo.filewatch.policy ${DESTDIR}${PREFIX}/share/PolicyKit/policy/org.kde.baloo.filewatch.policy
.endif

.include "../../devel/qjson/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
