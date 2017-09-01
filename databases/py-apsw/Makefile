# $NetBSD: Makefile,v 1.11 2017/09/01 10:14:41 adam Exp $

DISTNAME=	apsw-${GITHUB_RELEASE}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-r1//}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rogerbinns/}
GITHUB_PROJECT=	apsw
GITHUB_RELEASE=	3.20.1-r1
EXTRACT_SUFX=	.zip

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://github.com/rogerbinns/apsw
COMMENT=	Python wrapper for SQLite
LICENSE=	zlib

USE_LANGUAGES=	c
EGG_NAME=	${DISTNAME:S/-r1/.post1/}

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.18
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
