# $NetBSD: Makefile,v 1.9 2020/10/04 18:15:43 js Exp $

DISTNAME=	python-magic-0.4.18
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-magic/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ahupp/python-magic
COMMENT=	File type identification using libmagic
LICENSE=	mit

DEPENDS+=	file-[0-9]*:../../sysutils/file

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
