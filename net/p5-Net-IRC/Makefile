# $NetBSD: Makefile,v 1.7 2004/04/27 06:05:57 snj Exp $

DISTNAME=		Net-IRC-0.73
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5nir
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Net-IRC/Connection.html
COMMENT=		Perl Internet Relay Chat (IRC) module

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
