#	$NetBSD: Makefile,v 1.1 2020/08/17 07:00:58 riastradh Exp $

DISTNAME=	pyscard-1.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^py//}
CATEGORIES=	devel
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
