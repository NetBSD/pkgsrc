# $NetBSD: Makefile,v 1.14 2010/02/02 11:34:52 obache Exp $

DISTNAME=	IPy-0.70
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/IPy/IP/}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/I/IPy/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://software.inl.fr/trac/trac.cgi/wiki/IPy
COMMENT=	Python module to handle IPv4 and IPv6 address
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
