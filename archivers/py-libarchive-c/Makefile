# $NetBSD: Makefile,v 1.9 2017/05/29 11:09:45 jperkin Exp $

DISTNAME=	libarchive-c-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libarchive-c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Changaco/python-libarchive-c
COMMENT=	Python interface to libarchive
LICENSE=	cc0-1.0-universal

SUBST_CLASSES+=			libarchive
# assume for now that only pkgsrc provides a new enough version
SUBST_SED.libarchive+=		-e "s,find_library('archive'),'${PREFIX}/lib/libarchive.so',"
SUBST_FILES.libarchive+=	libarchive/ffi.py
SUBST_MESSAGE.libarchive=	Fix path to libarchive.
SUBST_STAGE.libarchive=		post-configure

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
