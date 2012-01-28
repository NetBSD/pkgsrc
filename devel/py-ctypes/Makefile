# $NetBSD: Makefile,v 1.8 2012/01/28 09:12:03 obache Exp $

DISTNAME=	ctypes-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctypes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/theller/ctypes/
COMMENT=	Foreign Function Interface package for Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	24

do-test:
	${PYTHONBIN} ${WRKSRC}/ctypes/test/runtests.py

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
