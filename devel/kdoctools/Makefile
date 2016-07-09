# $NetBSD: Makefile,v 1.2 2016/07/09 06:38:08 wiz Exp $

DISTNAME=	kdoctools-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Documentation generation from docbook
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	perl

BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
