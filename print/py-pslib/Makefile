# $NetBSD: Makefile,v 1.12 2020/01/18 23:33:30 rillig Exp $

DISTNAME=	python-pslib_0.2.0.orig
PKGNAME=	${PYPKGPREFIX}-pslib-0.2.0
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pslib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pslib.sourceforge.net/
COMMENT=	Python bindings for pslib


WRKSRC=		${WRKDIR}/python-pslib-0.2.0

EGG_NAME=	python_pslib-${PKGVERSION_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../print/pslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
