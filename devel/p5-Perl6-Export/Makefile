# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:29 wiz Exp $
#

DISTNAME=	Perl6-Export-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Perl6-Export/
COMMENT=	Implements the Perl 6 'is export(...)' trait

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl6/Export/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
