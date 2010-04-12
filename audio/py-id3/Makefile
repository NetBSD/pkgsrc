# $NetBSD: Makefile,v 1.1.1.1 2010/04/12 12:13:28 obache Exp $

DISTNAME=	id3-py_1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3-py/}

MAINTAINER=	wes.chow@s7labs.com
HOMEPAGE=	http://id3-py.sourceforge.net/
COMMENT=	Python module to manipulate ID3 tags in MP3 files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
