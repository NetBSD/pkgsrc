# $NetBSD: Makefile,v 1.13 2004/03/03 10:27:17 recht Exp $
#

DISTNAME=	pygoogle-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygoogle/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pygoogle.sourceforge.net/
COMMENT=	Call the Google web API from Python

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

.include "../../net/py-soappy/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
