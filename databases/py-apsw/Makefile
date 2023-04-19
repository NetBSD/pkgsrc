# $NetBSD: Makefile,v 1.53 2023/04/19 08:09:32 adam Exp $

DISTNAME=	apsw-3.41.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-r1//}
PKGREVISION=	1
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

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.41.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
