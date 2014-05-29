# $NetBSD: Makefile,v 1.10 2014/05/29 23:36:14 wiz Exp $
#

DISTNAME=	Readonly-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Readonly/
COMMENT=	Perl 5 module for creating read-only scalars, arrays and hashes
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	benchmark.pl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Readonly/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
