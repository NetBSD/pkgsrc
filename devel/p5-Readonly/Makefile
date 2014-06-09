# $NetBSD: Makefile,v 1.11 2014/06/09 18:54:52 schmonz Exp $
#

DISTNAME=	Readonly-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Readonly/
COMMENT=	Perl 5 module for creating read-only scalars, arrays and hashes
LICENSE=	${PERL5_LICENSE}

#REPLACE_PERL=	eg/benchmark.pl

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Readonly/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
