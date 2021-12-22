# $NetBSD: Makefile,v 1.48 2021/12/22 22:25:12 mef Exp $
TRYTON_MODULE_NAME=	tryton
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Three-tiers high-level general purpose application platform
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		# none

#WRKSRC=		${WRKDIR}/tryton-${PKGVERSION_NOREV}

.include "options.mk"

DEPENDS+=		${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=		${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS.Darwin+=	${PYPKGPREFIX}-py2app-[0-9]*:../../devel/py-py2app

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tryton \
		${DESTDIR}${PREFIX}/bin/tryton${PYVERSSUFFIX} || ${TRUE}

.include "../../graphics/librsvg/buildlink3.mk"
#include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
