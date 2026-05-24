# $NetBSD: Makefile,v 1.36 2026/05/24 20:55:53 wiz Exp $

.include "../../databases/rrdtool/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

WHEEL_NAME=	rrdtool-0.1.10

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

EXTRACT_ELEMENTS=	${DISTNAME}/bindings/python ${DISTNAME}/src
WRKSRC=			${WRKDIR}/${DISTNAME}/bindings/python
MAKE_ENV+=		ABS_TOP_BUILDDIR=${WRKDIR}/${DISTNAME}

pre-configure:
	${RM} ${WRKDIR}/${DISTNAME}/src/rrd_config.h

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
