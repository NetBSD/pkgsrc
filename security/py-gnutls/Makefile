# $NetBSD: Makefile,v 1.3 2004/02/25 16:09:47 minskim Exp $

DISTNAME=		python-gnutls-0.2
PKGNAME=		${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://home.o2w.net/~ivo/python-gnutls/dist/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://home.o2w.net/~ivo/wiki/moin.cgi/PythonGnutls
COMMENT=		Python bindings for GNUTLS

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes
NO_CONFIGURE=		yes

PYTHON_VERSIONS_ACCEPTED= 23 23pth

.include "../../lang/python/extension.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
