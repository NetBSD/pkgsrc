# $NetBSD: Makefile,v 1.7 2012/01/23 07:54:23 obache Exp $

DISTNAME=	python2-chardet-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python2-//}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	http://chardet.feedparser.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://chardet.feedparser.org/
COMMENT=	Character encoding auto-detection in Python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=	${DISTNAME:S/python2-//}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
