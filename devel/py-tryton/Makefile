# $NetBSD: Makefile,v 1.6 2014/05/03 13:09:55 rodent Exp $

DISTNAME=	tryton-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Three-tiers high-level general purpose application platform
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 # XXX Needs weakrefset. No package, though.
PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

.include "options.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-py2app-[0-9]*:../../devel/py-py2app
.endif

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tryton \
		${DESTDIR}${PREFIX}/bin/tryton${PYVERSSUFFIX}

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
