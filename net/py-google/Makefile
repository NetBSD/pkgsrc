# $NetBSD: Makefile,v 1.18 2004/08/13 08:57:14 recht Exp $
#

DISTNAME=	pygoogle-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygoogle/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pygoogle.sourceforge.net/
COMMENT=	Call the Google web API from Python

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../net/py-soappy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
