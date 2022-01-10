# $NetBSD: Makefile,v 1.3 2022/01/10 16:15:07 adam Exp $

DISTNAME=	pyscard-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyscard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyscard.sourceforge.io/
COMMENT=	Python library for smart cards
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	swig3>=0:../../devel/swig3

CPPFLAGS+=	-I${BUILDLINK_PREFIX.pcsc-lite}/include/PCSC

pre-configure:
	${LN} -sf ${PREFIX}/bin/swig3.0 ${BUILDLINK_DIR}/bin/swig

.include "../../lang/python/egg.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
