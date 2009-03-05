# $NetBSD: Makefile,v 1.3 2009/03/05 18:51:27 joerg Exp $
#

DISTNAME=	chardet-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://chardet.feedparser.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bartosz@atom.eu.org
HOMEPAGE=	http://chardet.feedparser.org/
COMMENT=	Character encoding auto-detection in Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
