# $NetBSD: Makefile,v 1.49 2024/02/06 11:05:16 markd Exp $

DISTNAME=	poxml-${KAPPSVER}
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/
COMMENT=	Translates DocBook XML files using gettext po files
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
