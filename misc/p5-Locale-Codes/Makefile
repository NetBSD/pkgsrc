# $NetBSD: Makefile,v 1.20 2005/04/11 21:46:39 tv Exp $

DISTNAME=		Locale-Codes-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lco
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Locale-Codes/Locale/Country.html
COMMENT=		Perl5 module providing access to ISO3166 and ISO639 Country Codes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
