# $NetBSD: Makefile,v 1.9 2014/05/09 07:37:10 wiz Exp $

DISTNAME=	libgmail-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libgmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libgmail.sourceforge.net/
COMMENT=	Python bindings to access Gmail
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mechanize-[0-9]*:../../www/py-mechanize

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mechanize

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
