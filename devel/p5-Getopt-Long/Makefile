# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:21 jlam Exp $

DISTNAME=		Getopt-Long-2.35
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JV/JV/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~rsavage/Getopt-Simple/
COMMENT=		Extended processing of command line options

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Getopt/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
