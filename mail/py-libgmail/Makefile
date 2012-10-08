# $NetBSD: Makefile,v 1.7 2012/10/08 12:19:28 asau Exp $
#

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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
