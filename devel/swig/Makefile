# $NetBSD: Makefile,v 1.7 2003/03/29 12:40:40 jmmv Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
WRKSRC=		${WRKDIR}/SWIG1.1p5
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../lang/python/pyversion.mk"

.include "../../lang/perl5/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
