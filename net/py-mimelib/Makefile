# $NetBSD: Makefile,v 1.13 2006/02/05 23:10:30 joerg Exp $
#

DISTNAME=	email-2.5
PKGNAME=	${PYPKGPREFIX}-mimelib-2.5
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/mimelib/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mimelib.sourceforge.net/
COMMENT=	Email package for Python

PYDISTUTILSPKG=	yes
# This pkg (or an older version of it) comes with 2.2 and later;
# 2.1 is the primary target (particulary for Zope).
PYTHON_VERSIONS_ACCEPTED= 21 22 23

.include "../../lang/python/extension.mk"

# _compat22.py is not byte-compiled if built with 2.1(-)
.if !empty(PYPKGPREFIX:Mpy21*)
PLIST_SUBST+=	NOT21="@comment "
.else
PLIST_SUBST+=	NOT21=""
.endif

.include "../../mk/bsd.pkg.mk"
