# $NetBSD: Makefile,v 1.15 2018/04/14 07:34:13 adam Exp $

DISTNAME=	apsw-${GITHUB_RELEASE}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-r1//}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rogerbinns/}
GITHUB_PROJECT=	apsw
GITHUB_RELEASE=	3.21.0-r1
EXTRACT_SUFX=	.zip

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://github.com/rogerbinns/apsw
COMMENT=	Python wrapper for SQLite
LICENSE=	zlib

USE_LANGUAGES=	c
EGG_NAME=	${DISTNAME:S/-r1/.post1/}

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.21
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
