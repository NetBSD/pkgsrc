# $NetBSD: Makefile,v 1.6 2004/05/02 03:55:16 snj Exp $

DISTNAME=	piddle-1.0.15
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=piddle/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://piddle.sf.net/
COMMENT=	Python Plug In Drawing, Does Little Else

PYDISTUTILSPKG=	# defined
USE_BUILDLINK3=	yes

NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
