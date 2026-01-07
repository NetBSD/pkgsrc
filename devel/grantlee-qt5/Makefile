# $NetBSD: Makefile,v 1.66 2026/01/07 08:46:30 wiz Exp $

DISTNAME=	grantlee-5.3.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=steveire/}
GITHUB_PROJECT=	grantlee
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/steveire/grantlee
COMMENT=	String template engine in QT5 based on Django template system
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
