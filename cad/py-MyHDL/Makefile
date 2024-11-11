# $NetBSD: Makefile,v 1.35 2024/11/11 07:27:53 wiz Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/myhdl/MyHDL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hardware description in Python

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${FIND} ${DESTDIR} -name '*.orig' -exec rm -rf '{}' ';'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
