# $NetBSD: Makefile,v 1.10 2023/08/14 05:25:21 wiz Exp $

DISTNAME=	csvtomd-0.1.1
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	https://github.com/mplewis/csvtomd/
COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
