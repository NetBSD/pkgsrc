# $NetBSD: Makefile,v 1.56 2023/01/29 21:15:51 ryoon Exp $
TRYTON_MODULE_NAME=	tryton
PKGREVISION= 7
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Three-tiers high-level general purpose application platform
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		# none

USE_PKG_RESOURCES=	yes

#WRKSRC=		${WRKDIR}/tryton-${PKGVERSION_NOREV}

.include "options.mk"

DEPENDS+=		${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=		${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=		${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS.Darwin+=	${PYPKGPREFIX}-py2app-[0-9]*:../../devel/py-py2app

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tryton \
		${DESTDIR}${PREFIX}/bin/tryton${PYVERSSUFFIX} || ${TRUE}

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
