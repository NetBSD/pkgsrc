# $NetBSD: Makefile,v 1.17 2020/01/18 23:32:49 rillig Exp $

DISTNAME=	libgmail-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libgmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libgmail.sourceforge.net/
COMMENT=	Python bindings to access Gmail
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mechanize-[0-9]*:../../www/py-mechanize

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # py-mechanize

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
