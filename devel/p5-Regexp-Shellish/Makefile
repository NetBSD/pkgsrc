# $NetBSD: Makefile,v 1.12 2012/10/31 11:18:52 asau Exp $

DISTNAME=	Regexp-Shellish-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RB/RBS/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for shell-like regular expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Regexp/Shellish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
