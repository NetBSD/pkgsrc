# $NetBSD: Makefile,v 1.2 2018/01/24 19:06:10 markd Exp $

DISTNAME=	kapidox-${KF5VER}
PKGREVISION=	1
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
