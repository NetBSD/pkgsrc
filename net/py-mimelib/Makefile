# $NetBSD: Makefile,v 1.17 2008/04/25 20:39:11 joerg Exp $
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
PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

.include "../../lang/python/extension.mk"

# _compat22.py is not byte-compiled if built with 2.1(-)
PLIST_VARS+=	compat22
.if ${_PYTHON_VERSION} != "21"
PLIST.compat22=	yes
.endif

.include "../../mk/bsd.pkg.mk"
