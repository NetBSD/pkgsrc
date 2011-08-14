# $NetBSD: Makefile,v 1.10 2011/08/14 12:26:33 obache Exp $

DISTNAME=	Regexp-Shellish-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RB/RBS/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for shell-like regular expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Regexp/Shellish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
