# $NetBSD: Makefile,v 1.4 2004/01/10 19:14:18 kristerw Exp $
#

DISTNAME=	email-2.5
PKGNAME=	${PYPKGPREFIX}-mimelib-2.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/mimelib/}

MAINTAINER=	tech-pkg@NetBSD.org
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
