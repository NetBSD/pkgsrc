# $NetBSD: Makefile,v 1.1.1.1 2003/08/11 14:56:54 drochner Exp $
#

DISTNAME=	email-2.5
PKGNAME=	${PYPKGPREFIX}-mimelib-2.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/mimelib/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mimelib.sourceforge.net/
COMMENT=	Email package for Python

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	yes
# This pkg (or an older version of it) comes with 2.2 and later;
# 2.1 is the primary target (particulary for Zope).
PYTHON_VERSIONS_ACCEPTED= 21pth 21 22 22pth 23 23pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
