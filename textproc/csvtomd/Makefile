# $NetBSD: Makefile,v 1.2 2016/07/28 09:49:04 cheusov Exp $

DISTNAME=	csvtomd-v0.1.1
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}

COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

GITHUB_PROJECT=	csvtomd
GITHUB_TAG=	${DISTNAME:S/csvtomd-//}
MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/mplewis/csvtomd/

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	27

#.include "../../lang/python/distutils.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
