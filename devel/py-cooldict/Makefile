# $NetBSD: Makefile,v 1.3 2022/01/22 15:31:14 wiz Exp $

DISTNAME=	cooldict-1.04
PKGNAME=	${PYPKGPREFIX}-cooldict-1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cooldict/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/zardus/cooldict
COMMENT=	Some useful dict-like structures
LICENSE=	2-clause-bsd

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
EGG_NAME=	cooldict-1.4
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
