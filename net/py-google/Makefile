# $NetBSD: Makefile,v 1.12 2004/01/20 12:22:20 agc Exp $
#

DISTNAME=	pygoogle-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	http://diveintomark.org/projects/pygoogle/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://diveintomark.org/projects/pygoogle/
COMMENT=	Call the Google web API from Python

WRKSRC=		${WRKDIR}/pygoogle
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-extract:
	${RM} ${WRKSRC}/soap.py

.include "../../net/py-soappy/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
