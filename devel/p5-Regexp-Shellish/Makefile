# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:34 tv Exp $

DISTNAME=	Regexp-Shellish-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RB/RBS/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for shell-like regular expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Regexp/Shellish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
