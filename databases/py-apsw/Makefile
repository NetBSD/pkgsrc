# $NetBSD: Makefile,v 1.56 2023/08/28 10:34:45 adam Exp $

DISTNAME=	apsw-3.43.0.0
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

PYSETUPBUILDARGS+=	--enable=load_extension

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.42.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
