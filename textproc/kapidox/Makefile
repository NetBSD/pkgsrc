# $NetBSD: Makefile,v 1.12 2023/04/17 19:42:47 adam Exp $

DISTNAME=	kapidox-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Frameworks API Documentation Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

INSTALL_DIRS=	# dont do cmake install, only python

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-yaml

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
