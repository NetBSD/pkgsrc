# $NetBSD: Makefile,v 1.1.1.1 2007/05/13 19:25:32 seb Exp $
#

DISTNAME=	Getopt-Euclid-v0.1.0
PKGNAME=	p5-Getopt-Euclid-0.1.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-Euclid/
COMMENT=	Perl 5 module to create command-line parser from documentation

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Getopt/Euclid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
