# $NetBSD: Makefile,v 1.8 2012/10/08 12:19:28 asau Exp $
#

VER=		1.0
DISTNAME=	sendmail-admin-${VER}
PKGNAME=	${PYPKGPREFIX}-sendmail-admin-${VER}
PKGREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	http://www.clapper.org/software/python/sendmail-admin/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.clapper.org/software/python/sendmail-admin/
COMMENT=	Mailqs and rmmq, two scripts that ease Sendmail administration
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_SELF_CONFLICT=		yes

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
