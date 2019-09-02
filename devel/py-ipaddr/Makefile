# $NetBSD: Makefile,v 1.15 2019/09/02 13:19:40 adam Exp $

DISTNAME=	ipaddr-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://googledrive.com/host/0B6wLlfdySbEUMkh1ZWhpZk1pZmc/
MASTER_SITES+=	${MASTER_SITE_PYPI:=i/ipaddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/ipaddr-py
COMMENT=	Google open source IPv4/IPv6 manipulation library in Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.1.10
REPLACE_PYTHON+=		ipaddr.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
