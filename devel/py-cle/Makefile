# $NetBSD: Makefile,v 1.2 2020/01/09 14:02:31 wiz Exp $

DISTNAME=	cle-8.20.1.7
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	cle
GITHUB_TAG=	de4499da5970aab8f762a43a5dccf8a4a472da12

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/cle/
COMMENT=	CLE Loads Everything (at least, many binary formats!)
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
