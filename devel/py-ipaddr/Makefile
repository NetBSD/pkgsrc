# $NetBSD: Makefile,v 1.16 2022/01/10 09:13:07 wiz Exp $

DISTNAME=	ipaddr-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://googledrive.com/host/0B6wLlfdySbEUMkh1ZWhpZk1pZmc/
MASTER_SITES+=	${MASTER_SITE_PYPI:=i/ipaddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/ipaddr-py
COMMENT=	Google open source IPv4/IPv6 manipulation library in Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.1.10
REPLACE_PYTHON+=		ipaddr.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
