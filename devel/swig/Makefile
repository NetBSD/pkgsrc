# $NetBSD: Makefile,v 1.9 2004/03/08 19:52:51 minskim Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

WRKSRC=		${WRKDIR}/SWIG1.1p5
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../lang/python/pyversion.mk"

.include "../../lang/perl5/buildlink2.mk"
.include "../../lang/tcl83/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
