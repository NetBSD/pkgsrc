# $NetBSD: Makefile,v 1.23 2006/01/24 07:32:31 wiz Exp $
#

DISTNAME=	pygoogle-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygoogle/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pygoogle.sourceforge.net/
COMMENT=	Call the Google web API from Python

PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_ACCEPTED=       23 22 21

.include "../../lang/python/extension.mk"
.include "../../net/py-soappy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
