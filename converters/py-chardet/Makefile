# $NetBSD: Makefile,v 1.4 2009/03/21 21:38:09 snj Exp $

DISTNAME=	chardet-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://chardet.feedparser.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://chardet.feedparser.org/
COMMENT=	Character encoding auto-detection in Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
