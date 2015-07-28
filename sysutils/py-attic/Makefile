# $NetBSD: Makefile,v 1.3 2015/07/28 23:54:29 riz Exp $

DISTNAME=	Attic-0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/A/Attic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://attic-backup.org/
COMMENT=	Deduplicating backup program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack

PYTHON_VERSIONS_INCOMPATIBLE=	27
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv attic attic${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
