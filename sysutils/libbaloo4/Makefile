# $NetBSD: Makefile,v 1.30 2022/01/10 01:46:44 ryoon Exp $

DISTNAME=	baloo-${_KDE_VERSION}
PKGNAME=	libbaloo4-${_KDE_VERSION}
PKGREVISION=	29
CATEGORIES=	sysutils
COMMENT=	KDE framework for searching and managing user metadata
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

CONFLICTS+=	baloo<4.14.3nb4

USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../mk/bsd.prefs.mk"

post-install:
	rm -rf ${DESTDIR}${PREFIX}/bin
	rm -rf ${DESTDIR}${PREFIX}/share/PolicyKit
	rm -rf ${DESTDIR}${PREFIX}/share/akonadi
	rm -rf ${DESTDIR}${PREFIX}/share/dbus-1
	rm -rf ${DESTDIR}${PREFIX}/share/icons
	rm -rf ${DESTDIR}${PREFIX}/share/polkit-1

.include "../../devel/qjson/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
