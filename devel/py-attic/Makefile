# $NetBSD: Makefile,v 1.3 2015/04/16 08:04:37 wiz Exp $

DISTNAME=	Attic-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/A/Attic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://attic-backup.org/
COMMENT=	Deduplicating backup program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack

PYTHON_VERSIONS_INCOMPATIBLE=	27
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv attic attic${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
