# $NetBSD: Makefile,v 1.13 2002/10/07 22:34:23 seb Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/06/27 01:51:12 jfitz Exp
#

DISTNAME=		Locale-Codes-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lco
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Locale-Codes/Locale/Country.html
COMMENT=		perl5 module providing access to ISO3166 and ISO639 Country Codes

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
