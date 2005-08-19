# $NetBSD: Makefile,v 1.1.1.1 2005/08/19 16:06:03 drochner Exp $
#

DISTNAME=		python-pslib_0.2.0.orig
PKGNAME=		${PYPKGPREFIX}-pslib-0.2.0
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pslib.sourceforge.net/
COMMENT=		Python bindings for pslib

WRKSRC=		${WRKDIR}/python-pslib-0.2.0
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../print/pslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
