# $NetBSD: Makefile,v 1.78 2024/12/09 08:35:32 adam Exp $

DISTNAME=	apsw-3.47.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-r1//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rogerbinns/}
EXTRACT_SUFX=	.zip
GITHUB_PROJECT=	apsw
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://github.com/rogerbinns/apsw
COMMENT=	Python wrapper for SQLite
LICENSE=	zlib

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.0:../../devel/py-setuptools

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} apsw apsw-${PYVERSSUFFIX} || ${TRUE}

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=${PKGVERSION_NOREV:R}
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
