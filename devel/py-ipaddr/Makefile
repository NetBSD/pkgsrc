# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:01 wiz Exp $

DISTNAME=	ipaddr-2.1.10
PKGNAME=	${PYPKGPREFIX}ipaddr-2.1.10
CATEGORIES=	devel python
MASTER_SITES=	http://ipaddr-py.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ipaddr-py/
COMMENT=	Google open source IPv4/IPv6 manipulation library in Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.1.10

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
