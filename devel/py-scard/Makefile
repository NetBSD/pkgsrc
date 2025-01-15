# $NetBSD: Makefile,v 1.14 2025/01/15 08:43:35 adam Exp $

DISTNAME=	pyscard-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyscard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyscard.sourceforge.io/
COMMENT=	Python library for smart cards
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	swig3>=0:../../devel/swig3
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

CPPFLAGS+=	-I${BUILDLINK_PREFIX.pcsc-lite}/include/PCSC

pre-configure:
	${LN} -sf ${TOOLBASE}/bin/swig3.0 ${BUILDLINK_DIR}/bin/swig

.include "../../lang/python/wheel.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
