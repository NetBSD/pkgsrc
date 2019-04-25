# $NetBSD: Makefile,v 1.5 2019/04/25 07:33:23 maya Exp $

DISTNAME=	csvtomd-0.1.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	https://github.com/mplewis/csvtomd/
COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
