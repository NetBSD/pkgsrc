# $NetBSD: Makefile,v 1.3 2018/08/01 13:40:41 gdt Exp $

DISTNAME=	configobj-5.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/configobj/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.voidspace.org.uk/python/configobj.html
COMMENT=	Simple but powerful config file reader and write
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
