# $NetBSD: Makefile,v 1.20 2022/08/11 05:08:45 gutteridge Exp $

DISTNAME=	paper-icon-theme-1.5.0
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=snwh/}
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/snwh/paper-icon-theme
COMMENT=	Modern freedesktop icon theme
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

ICON_THEMES=	yes

REPLACE_PYTHON+=	meson/post_install.py

CHECK_WRKREF_SKIP+=		share/icons/*/*/*/*
CHECK_INTERPRETER_SKIP+=	share/icons/*/*/*/*

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/meson/build.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
