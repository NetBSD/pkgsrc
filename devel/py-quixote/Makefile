# $NetBSD: Makefile,v 1.1.1.1 2009/03/03 10:12:38 manu Exp $
#

PKGNAME=	${PYPKGPREFIX}-quixote
DISTNAME=	Quixote-2.6
CATEGORIES=	devel www
MASTER_SITES=	http://quixote.ca/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://quixote.ca/
COMMENT=	Framework for writing Python web application

PKG_DESTDIR_SUPPORT=	destdir

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
