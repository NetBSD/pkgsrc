# $NetBSD: Makefile,v 1.6 2002/09/29 06:56:18 jlam Exp $

DISTNAME=		udunits
PKGNAME=		udunits-1.11.7
CATEGORIES=		math devel
MASTER_SITES=		http://www.unidata.ucar.edu/packages/udunits/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.unidata.ucar.edu/packages/udunits/
COMMENT=		Library and program for manipulating units of physical quantities

WRKSRC=			${WRKDIR}/${PKGNAME}/src
DIST_SUBDIR=		${PKGNAME}

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/UDUNITS/.packlist

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
