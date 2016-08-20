# $NetBSD: Makefile,v 1.7 2016/08/20 18:56:55 richard Exp $

DISTNAME=	obspy-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/obspy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.obspy.org/
COMMENT=	Python framework for seismological observatories
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-future>=0.12.4:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0:../../databases/py-sqlalchemy

USE_LANGUAGES=	c fortran
USE_TOOLS+=	bash:run

REPLACE_BASH=	obspy/taup/tests/data/TauP_test_data/gendata.sh

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/python/pyversion.mk"

PYPLATFORM!=	${PYTHONBIN} -c 'import platform; print platform.system() + "_" + platform.architecture()[0]'

PLIST_SUBST+=		PYPLATFORM=${PYPLATFORM} PYPKGPREFIX=${PYPKGPREFIX}
PRINT_PLIST_AWK+=       /^${PYPLATFORM:S|/|\\/|g}/ \
                        { gsub(/${PYPLATFORM:S|/|\\/|g}/, "$${PYPLATFORM}") }

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
