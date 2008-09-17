# $NetBSD: Makefile,v 1.6 2008/09/17 16:20:21 joerg Exp $

DISTNAME=	ctypes-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctypes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/theller/ctypes/
COMMENT=	Foreign Function Interface package for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-test:
	${PYTHONBIN} ${WRKSRC}/ctypes/test/runtests.py

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
