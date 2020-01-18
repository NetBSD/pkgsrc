# $NetBSD: Makefile,v 1.8 2020/01/18 21:50:56 jperkin Exp $

DISTNAME=	Attic-0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Attic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://attic-backup.org/
COMMENT=	Deduplicating backup program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} attic attic${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
