# $NetBSD: Makefile,v 1.10 2005/04/11 21:46:54 tv Exp $

DISTNAME=		Net-IRC-0.75
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5nir
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Net-IRC/
COMMENT=		Perl Internet Relay Chat (IRC) module

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
