# $NetBSD: Makefile,v 1.23 2018/07/03 05:03:31 adam Exp $

DISTNAME=	GnuPGInterface-0.3.2
PKGNAME=	${PYPKGPREFIX}-gnupg-0.3.2
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=py-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://py-gnupg.sourceforge.net/
COMMENT=	Python module for GnuPG interface
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
