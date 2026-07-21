# $NetBSD: Makefile,v 1.44 2026/07/21 14:40:49 he Exp $

DISTNAME=	msgpack-1.2.1
# Please note that py-borgackup has a "maximally supported version"
# of this particular package coded into it, potentially causing
# a run-time error for py-borgbackup after a package upgrade.
# Ref. the two recently re-instated patches to py-borgbackup.
# So when updating this package, py-borgbackup will probably
# require attention too(!)
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msgpack/msgpack-python
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
