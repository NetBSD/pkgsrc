# $NetBSD: Makefile,v 1.2 2011/09/12 12:06:18 obache Exp $

DISTNAME=	id3-py_1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3-py/}

MAINTAINER=	wes.chow@s7labs.com
HOMEPAGE=	http://id3-py.sourceforge.net/
COMMENT=	Python module to manipulate ID3 tags in MP3 files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
EGG_NAME=	${DISTNAME:S/py_//:tu}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
