# $NetBSD: Makefile,v 1.22 2012/09/15 10:04:12 obache Exp $
#

DISTNAME=	kdevplatform-1.2.3
PKGREVISION=	5
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=kdevelop/4.2.3/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	frank@fthieme.net
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	KDE development platform, used by KDevelop 4
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+= automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	pkg-config perl msgfmt
USE_LANGUAGES=	c c++

CXXFLAGS.Linux+=	-fpermissive

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
