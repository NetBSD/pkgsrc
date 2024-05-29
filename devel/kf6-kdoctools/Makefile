# $NetBSD: Makefile,v 1.2 2024/05/29 16:32:08 adam Exp $

DISTNAME=	kdoctools-${KF6VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Documentation generation from docbook
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge perl

TOOL_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
