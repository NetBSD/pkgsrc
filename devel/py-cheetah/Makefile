# $NetBSD: Makefile,v 1.15 2013/02/01 22:21:06 wiz Exp $

DISTNAME=	Cheetah-2.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/C/Cheetah/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cheetahtemplate.org/
COMMENT=	Python-powered template engine and code-generator

CONFLICTS=	Cheetah-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.0.1:../../textproc/py-markdown

USE_LANGUAGES=		c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
