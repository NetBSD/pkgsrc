# $NetBSD: Makefile,v 1.10 2003/09/21 18:11:22 jmc Exp $
#

DISTNAME=	pygoogle-0.5.2
PKGNAME=	${PYPKGPREFIX}-google-0.5.2
PKGREVISION=	2
WRKSRC=		${WRKDIR}/pygoogle
CATEGORIES=	net
MASTER_SITES=	http://diveintomark.org/projects/pygoogle/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://diveintomark.org/projects/pygoogle/
COMMENT=	Call the Google web API from Python

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-extract:
	${RM} ${WRKSRC}/soap.py

.include "../../net/py-soappy/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
