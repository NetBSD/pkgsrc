# $NetBSD: Makefile,v 1.5 2002/01/23 19:34:46 tron Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

USE_PERL5=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/SWIG1.1p5

.include "../../lang/python/pyversion.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
