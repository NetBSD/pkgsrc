# $NetBSD: Makefile,v 1.5 2004/03/26 02:27:53 wiz Exp $

DISTNAME=		python-gnutls-0.2
PKGNAME=		${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=		3
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
