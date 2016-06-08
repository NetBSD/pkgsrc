# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:39 wiz Exp $

DISTNAME=	python-magic-0.4.6
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
CATEGORIES=	python sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-magic/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://github.com/ahupp/python-magic
COMMENT=	File type identification using libmagic
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
