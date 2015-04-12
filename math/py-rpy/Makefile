# $NetBSD: Makefile,v 1.37 2015/04/12 10:04:08 wiz Exp $

DISTNAME=	rpy2-2.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/rpy2/rpy/}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rpy2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES+=		c fortran77

BUILDLINK_API_DEPENDS.R+= R>=2.11.0

LDFLAGS.SunOS+=		-mimpure-text

PYTHON_VERSIONS_INCOMPATIBLE=	26 # doesn't find R
REPLACE_PYTHON=			rpy/tests.py

.include "../../lang/python/pyversion.mk"

PLIST_VARS=	sd
.if ${PYPKGPREFIX} == "py26" || ${PYPKGPREFIX} == "py27" || ${PYPKGPREFIX} == "py33"
PLIST.sd=	yes
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../devel/py-singledispatch
.endif
.if ${PYPKGPREFIX} == "py26"
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
