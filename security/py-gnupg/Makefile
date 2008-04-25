# $NetBSD: Makefile,v 1.13 2008/04/25 20:39:11 joerg Exp $

DISTNAME=	GnuPGInterface-0.3.2
PKGNAME=	${PYPKGPREFIX}-gnupg-0.3.2
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=py-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://py-gnupg.sourceforge.net/
COMMENT=	Python module for GnuPG interface

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
