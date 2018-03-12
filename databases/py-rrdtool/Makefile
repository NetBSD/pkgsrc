# $NetBSD: Makefile,v 1.2 2018/03/12 11:16:14 wiz Exp $

PKGREVISION= 1
.include "../../databases/rrdtool/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.8:../../devel/py-setuptools

EGG_NAME=	rrdtool-0.1.10

EXTRACT_ELEMENTS=	${DISTNAME}/bindings/python ${DISTNAME}/src
WRKSRC=			${WRKDIR}/${DISTNAME}/bindings/python
MAKE_ENV+=		ABS_TOP_BUILDDIR=${WRKDIR}/${DISTNAME}

pre-configure:
	rm ${WRKDIR}/${DISTNAME}/src/rrd_config.h

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
