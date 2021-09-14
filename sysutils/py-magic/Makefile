# $NetBSD: Makefile,v 1.13 2021/09/14 20:23:04 js Exp $

DISTNAME=	python-magic-0.4.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
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
