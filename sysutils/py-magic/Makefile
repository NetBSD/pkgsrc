# $NetBSD: Makefile,v 1.15 2022/02/02 12:29:14 adam Exp $

DISTNAME=	python-magic-0.4.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
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
