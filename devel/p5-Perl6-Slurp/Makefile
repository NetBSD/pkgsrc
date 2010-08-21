# $NetBSD: Makefile,v 1.5 2010/08/21 16:34:18 seb Exp $
#

DISTNAME=	Perl6-Slurp-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Perl6-Slurp/
COMMENT=	Implements the Perl 6 'slurp' built-in

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Perl6-Export-[0-9]*:../../devel/p5-Perl6-Export

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl6/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
