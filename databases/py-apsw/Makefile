# $NetBSD: Makefile,v 1.38 2021/08/23 08:22:19 adam Exp $

DISTNAME=	apsw-${GITHUB_RELEASE}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-r1//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rogerbinns/}
EXTRACT_SUFX=	.zip
GITHUB_PROJECT=	apsw
GITHUB_RELEASE=	3.36.0-r1

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://github.com/rogerbinns/apsw
COMMENT=	Python wrapper for SQLite
LICENSE=	zlib

EGG_NAME=	${DISTNAME:S/-r1/.post1/}

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.36.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
