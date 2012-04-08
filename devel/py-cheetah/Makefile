# $NetBSD: Makefile,v 1.13 2012/04/08 19:08:51 wiz Exp $

DISTNAME=	Cheetah-2.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/C/Cheetah/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.cheetahtemplate.org/
COMMENT=	Python-powered template engine and code-generator

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	Cheetah-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.0.1:../../textproc/py-markdown

USE_LANGUAGES=		c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
