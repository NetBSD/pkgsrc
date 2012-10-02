# $NetBSD: Makefile,v 1.3 2012/10/02 23:48:05 asau Exp $

DISTNAME=	id3-py_1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3-py/}

MAINTAINER=	wes.chow@s7labs.com
HOMEPAGE=	http://id3-py.sourceforge.net/
COMMENT=	Python module to manipulate ID3 tags in MP3 files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# empty

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
EGG_NAME=	${DISTNAME:S/py_//:tu}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
