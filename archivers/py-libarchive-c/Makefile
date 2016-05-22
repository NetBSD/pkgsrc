# $NetBSD: Makefile,v 1.4 2016/05/22 13:15:43 wiz Exp $

DISTNAME=	libarchive-c-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libarchive-c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Changaco/python-libarchive-c
COMMENT=	Python interface to libarchive
LICENSE=	gnu-lgpl-v2

SUBST_CLASSES+=			libarchive
# assume for now that only pkgsrc provides a new enough version
SUBST_SED.libarchive+=		-e "s,find_library('archive'),'${PREFIX}/lib/libarchive.so',"
SUBST_FILES.libarchive+=	libarchive/ffi.py
SUBST_MESSAGE.libarchive=	Fix path to libarchive.
SUBST_STAGE.libarchive=		post-configure

# permissions are usually wrong
post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
