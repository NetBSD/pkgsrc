# $NetBSD: Makefile,v 1.40 2025/01/27 13:29:40 wiz Exp $

DISTNAME=	xca-2.8.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=chris2511/}
GITHUB_RELEASE=	RELEASE.${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hohnstaedt.de/xca/
COMMENT=	Certificate and key management
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config perl
USE_LANGUAGES=		c c++

REPLACE_PERL+=		doc/code2html

.include "../../devel/cmake/build.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
