# $NetBSD: Makefile,v 1.11 2012/10/03 21:55:32 wiz Exp $

DISTNAME=	Regexp-Shellish-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RB/RBS/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for shell-like regular expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Regexp/Shellish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
