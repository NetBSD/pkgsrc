# $NetBSD: Makefile,v 1.5 2001/06/11 06:34:43 jlam Exp $

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
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix
USE_PERL5=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/UDUNITS/.packlist

.include "../../mk/bsd.pkg.mk"
