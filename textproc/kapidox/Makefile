# $NetBSD: Makefile,v 1.10 2022/06/30 11:18:54 nia Exp $

DISTNAME=	kapidox-${KF5VER}
PKGREVISION=	1
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Frameworks API Documentation Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
