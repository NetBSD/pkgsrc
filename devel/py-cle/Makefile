# $NetBSD: Makefile,v 1.1 2018/03/15 02:32:56 khorben Exp $

DISTNAME=	cle-7.8.2.21
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	cle
GITHUB_TAG=	13a47181d5200fd24c5c956e893b0a95d26d4da7

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/cle/
COMMENT=	CLE Loads Everything (at least, many binary formats!)
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
