# $NetBSD: Makefile,v 1.6 2004/07/22 09:16:04 recht Exp $

DISTNAME=	GnuPGInterface-0.3.2
PKGNAME=	${PYPKGPREFIX}-gnupg-0.3.2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=py-gnupg/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://py-gnupg.sourceforge.net/
COMMENT=	Python module for GnuPG interface

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg

PYTHON_VERSIONS_ACCEPTED=	21
PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
