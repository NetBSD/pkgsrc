# $NetBSD: Makefile,v 1.7 2004/07/22 09:16:02 recht Exp $

DISTNAME=	piddle-1.0.15
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=piddle/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://piddle.sf.net/
COMMENT=	Python Plug In Drawing, Does Little Else

PYDISTUTILSPKG=	# defined
USE_BUILDLINK3=	yes

NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
