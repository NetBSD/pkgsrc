# $NetBSD: Makefile,v 1.45 2025/04/07 23:44:11 gdt Exp $

DISTNAME=	ruamel.yaml-0.18.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yaml.readthedocs.io/
COMMENT=	YAML parser/emitter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-clib>=0.2.7:../../devel/py-ruamel-yaml-clib

# The distfile uses '.' and the pkgsrc package uses '-'.  The
# wheelname uses '.' with old wheel code, such as is vendored in
# setuptools 75, and '_' with wheel >=0.45.1 (and likely setuptools
# 76).  Until then, force wheel so that the new code is used.
# (Afterwards, drop the TOOL_DEPENDS, keep WHEEL_NAME, and rewrite the
# comment.)
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.45.1:../../devel/py-wheel
WHEEL_NAME=	${DISTNAME:S/./_/1}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
