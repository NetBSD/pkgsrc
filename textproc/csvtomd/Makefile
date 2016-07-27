# $NetBSD: Makefile,v 1.1 2016/07/27 23:15:45 cheusov Exp $

DISTNAME=	csvtomd-v0.1.1
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mplewis/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	${MASTER_SITE_GITHUB:=mplewis/csvtomd/}
COMMENT=	Convert your CSV files into Markdown tables
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	csvtomd
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	27

#.include "../../lang/python/distutils.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
