# $NetBSD: Makefile,v 1.6 2002/09/24 10:30:35 jlam Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/SWIG1.1p5

.include "../../lang/python/pyversion.mk"

.include "../../lang/perl5/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
