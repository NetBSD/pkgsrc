# $NetBSD: Makefile,v 1.9 2022/06/30 11:18:53 nia Exp $

DISTNAME=	csvtomd-0.1.1
PKGREVISION=	5
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
