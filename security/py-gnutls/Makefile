# $NetBSD: Makefile,v 1.8 2005/01/23 20:41:49 recht Exp $

DISTNAME=		python-gnutls-0.2
PKGNAME=		${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=		4
CATEGORIES=		security python
MASTER_SITES=		http://home.o2w.net/~ivo/python-gnutls/dist/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://home.o2w.net/~ivo/wiki/moin.cgi/PythonGnutls
COMMENT=		Python bindings for GNUTLS

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes
NO_CONFIGURE=		yes

PYTHON_VERSIONS_ACCEPTED= 23

.include "../../lang/python/extension.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
