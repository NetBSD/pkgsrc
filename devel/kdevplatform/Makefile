# $NetBSD: Makefile,v 1.94 2020/06/02 08:23:38 adam Exp $
#

DISTNAME=	kdevplatform-1.7.0
PKGREVISION=	37
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=kdevelop/4.7.0/src/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	frank@fthieme.net
HOMEPAGE=	https://www.kdevelop.org/
COMMENT=	KDE development platform, used by KDevelop 4
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	pkg-config perl msgfmt bash:run
USE_LANGUAGES=	c c++

# sublime uses "auto",  -std=c++11 is set
GCC_REQD+=	4.7

CXXFLAGS.Linux+=	-fpermissive
LDFLAGS.SunOS+=		-lsocket -lnsl

REPLACE_BASH+= \
	util/kdevplatform_shell_environment.sh \
	util/kdev_format_source

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/grantlee/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
