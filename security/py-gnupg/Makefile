# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:45 joerg Exp $

DISTNAME=	GnuPGInterface-0.3.2
PKGNAME=	${PYPKGPREFIX}-gnupg-0.3.2
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=py-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://py-gnupg.sourceforge.net/
COMMENT=	Python module for GnuPG interface

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
