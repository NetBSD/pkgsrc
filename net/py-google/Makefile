# $NetBSD: Makefile,v 1.20 2004/10/03 00:17:57 tv Exp $
#

DISTNAME=	pygoogle-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygoogle/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pygoogle.sourceforge.net/
COMMENT=	Call the Google web API from Python

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED=       23pth 22pth 21pth

.include "../../lang/python/extension.mk"
.include "../../net/py-soappy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
