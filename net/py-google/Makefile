# $NetBSD: Makefile,v 1.3 2002/10/24 13:05:33 drochner Exp $
#

DISTNAME=	pygoogle-0.5.2
PKGNAME=	${PYPKGPREFIX}-google-0.5.2
CATEGORIES=	net
MASTER_SITES=	http://diveintomark.org/projects/pygoogle/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://diveintomark.org/projects/pygoogle/
COMMENT=	call the Google web API from Python

WRKSRC=		${WRKDIR}/pygoogle
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-extract:
	${RM} ${WRKSRC}/soap.py

.include "../../net/py-soappy/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
