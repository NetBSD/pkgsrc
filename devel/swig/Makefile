# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:33 tv Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

WRKSRC=		${WRKDIR}/SWIG1.1p5
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../lang/python/pyversion.mk"

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
