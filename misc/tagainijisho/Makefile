# $NetBSD: Makefile,v 1.7 2023/11/08 13:20:13 wiz Exp $

DISTNAME=	tagainijisho-1.2.2
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gnurou/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Gnurou/tagainijisho/
COMMENT=	Japanese dictionary and learning assistant
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
