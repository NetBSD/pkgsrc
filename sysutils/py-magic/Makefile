# $NetBSD: Makefile,v 1.7 2018/03/29 21:18:01 khorben Exp $

DISTNAME=	python-magic-0.4.15
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-magic/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ahupp/python-magic
COMMENT=	File type identification using libmagic
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
