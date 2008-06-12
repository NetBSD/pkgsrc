# $NetBSD: Makefile,v 1.3 2008/06/12 00:18:50 joerg Exp $
#

DISTNAME=	libgmail-0.1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libgmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libgmail/
COMMENT=	Python bindings to access Google mail

PYTHON_VERSIONS_ACCEPTED=	25 24
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
