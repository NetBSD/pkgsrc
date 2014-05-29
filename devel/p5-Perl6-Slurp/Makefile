# $NetBSD: Makefile,v 1.11 2014/05/29 23:36:13 wiz Exp $

DISTNAME=	Perl6-Slurp-0.051003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Perl6-Slurp/
COMMENT=	Implements the Perl 6 'slurp' built-in

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Perl6-Export-[0-9]*:../../devel/p5-Perl6-Export

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl6/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
