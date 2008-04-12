# $NetBSD: Makefile,v 1.15 2008/04/12 22:43:08 jlam Exp $
#

DISTNAME=	email-2.5
PKGNAME=	${PYPKGPREFIX}-mimelib-2.5
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/mimelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mimelib.sourceforge.net/
COMMENT=	Email package for Python

PYDISTUTILSPKG=	yes
# This pkg (or an older version of it) comes with 2.2 and later;
# 2.1 is the primary target (particulary for Zope).
PYTHON_VERSIONS_ACCEPTED= 21 22 23

.include "../../lang/python/extension.mk"

# _compat22.py is not byte-compiled if built with 2.1(-)
PLIST_VARS+=	compat22
.if !empty(PYPKGPREFIX:Mpy21*)
# nothing
.else
PLIST.compat22=	yes
.endif

.include "../../mk/bsd.pkg.mk"
