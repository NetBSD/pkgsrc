# $NetBSD: Makefile,v 1.14 2024/02/06 10:46:31 markd Exp $

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
