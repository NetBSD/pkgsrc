# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:39 joerg Exp $
#

DISTNAME=		python-pslib_0.2.0.orig
PKGNAME=		${PYPKGPREFIX}-pslib-0.2.0
PKGREVISION=		2
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
