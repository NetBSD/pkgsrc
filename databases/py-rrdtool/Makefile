# $NetBSD: Makefile,v 1.22 2023/11/14 14:01:33 wiz Exp $

PKGREVISION= 5
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
