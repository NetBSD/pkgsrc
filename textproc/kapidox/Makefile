# $NetBSD: Makefile,v 1.1 2016/05/26 09:26:56 markd Exp $

DISTNAME=	kapidox-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Frameworks API Documentation Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../meta-pkgs/kf5/Makefile.common"

PYDISTUTILSPKG=	YES
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
