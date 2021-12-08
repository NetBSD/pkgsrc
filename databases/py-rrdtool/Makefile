# $NetBSD: Makefile,v 1.13 2021/12/08 16:03:48 adam Exp $

PKGREVISION= 7
.include "../../databases/rrdtool/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

EGG_NAME=	rrdtool-0.1.10

EXTRACT_ELEMENTS=	${DISTNAME}/bindings/python ${DISTNAME}/src
WRKSRC=			${WRKDIR}/${DISTNAME}/bindings/python
MAKE_ENV+=		ABS_TOP_BUILDDIR=${WRKDIR}/${DISTNAME}

pre-configure:
	${RM} ${WRKDIR}/${DISTNAME}/src/rrd_config.h

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
