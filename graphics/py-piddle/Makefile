# $NetBSD: Makefile,v 1.4 2003/09/21 09:33:29 jmc Exp $

DISTNAME=	piddle-1.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=piddle/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://piddle.sf.net/
COMMENT=	Python Plug In Drawing, Does Little Else

PYDISTUTILSPKG=	# defined
USE_BUILDLINK2=	yes

NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
