# $NetBSD: Makefile,v 1.3 2014/01/25 10:30:17 wiz Exp $

DISTNAME=	suds-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/s/suds/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/suds/
COMMENT=	Lightweight SOAP python client for consuming Web Services
LICENSE=	gnu-lgpl-v3

EGG_NAME=		${DISTNAME}
USE_LANGUAGES=		# empty
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
