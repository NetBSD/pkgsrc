# $NetBSD: Makefile,v 1.15 2025/11/17 11:01:20 wiz Exp $

DISTNAME=	python-pslib_0.2.0.orig
PKGNAME=	${PYPKGPREFIX}-pslib-0.2.0
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pslib.sourceforge.net/
COMMENT=	Python bindings for pslib


WRKSRC=		${WRKDIR}/python-pslib-0.2.0

EGG_NAME=	python_pslib-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../print/pslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
