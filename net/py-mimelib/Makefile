# $NetBSD: Makefile,v 1.3 2003/12/24 09:53:49 jmmv Exp $
#

DISTNAME=	email-2.5
PKGNAME=	${PYPKGPREFIX}-mimelib-2.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/mimelib/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://mimelib.sourceforge.net/
COMMENT=	Email package for Python

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	yes
# This pkg (or an older version of it) comes with 2.2 and later;
# 2.1 is the primary target (particulary for Zope).
PYTHON_VERSIONS_ACCEPTED= 21pth 21 22 22pth 23 23pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# _compat22.py is not byte-compiled if built with 2.1(-pth)
.if !empty(PYPKGPREFIX:Mpy21*)
NOT21=	"@comment "
.else
NOT21=	#empty
.endif
PLIST_SUBST+=	NOT21=${NOT21}
