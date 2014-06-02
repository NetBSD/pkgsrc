# $NetBSD: Makefile,v 1.1 2014/06/02 00:12:59 rodent Exp $

DISTNAME=	python-magic-0.4.6
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
CATEGORIES=	python sysutils
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-magic/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://github.com/ahupp/python-magic
COMMENT=	File type identification using libmagic
LICENSE=	python-software-foundation

EGG_NAME=	${DISTNAME:S/-magic/_magic/}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
