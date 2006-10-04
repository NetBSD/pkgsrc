# $NetBSD: Makefile,v 1.14 2006/10/04 21:58:14 wiz Exp $

DISTNAME=	python-gnutls-0.2
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	8
CATEGORIES=	security python
MASTER_SITES=	http://home.o2w.net/~ivo/python-gnutls/dist/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.lychnis.net/wiki/PythonGnutls
COMMENT=	Python bindings for GNUTLS

WRKSRC=			${WRKDIR}/${DISTNAME}/src
PYDISTUTILSPKG=		yes
NO_CONFIGURE=		yes

PYTHON_VERSIONS_ACCEPTED= 23

.include "../../lang/python/extension.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
