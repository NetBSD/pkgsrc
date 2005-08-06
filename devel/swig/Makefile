# $NetBSD: Makefile,v 1.13 2005/08/06 06:19:18 jlam Exp $

DISTNAME=       swig1.1p5
PKGNAME=	swig-1.1p5
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.swig.org/pub/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

WRKSRC=		${WRKDIR}/SWIG1.1p5
GNU_CONFIGURE=	YES

.include "../../lang/python/pyversion.mk"

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
