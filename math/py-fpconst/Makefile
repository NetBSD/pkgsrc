# $NetBSD: Makefile,v 1.3 2004/06/27 22:59:48 recht Exp $
#

DISTNAME=	fpconst-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://www.analytics.washington.edu/~warnes/fpconst/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.analytics.washington.edu/statcomp/projects/rzope/fpconst/
COMMENT=	IEEE 754 floating point special handling for Python

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
