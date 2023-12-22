# $NetBSD: Makefile,v 1.54 2023/12/22 21:06:23 wiz Exp $

DISTNAME=	grantlee-5.3.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	3
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

.include "../../devel/cmake/build.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
