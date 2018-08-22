# $NetBSD: Makefile,v 1.19 2018/08/22 09:44:34 wiz Exp $
#

DISTNAME=	Readonly-2.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Readonly/
COMMENT=	Perl 5 module for creating read-only scalars, arrays and hashes
LICENSE=	${PERL5_LICENSE}

#REPLACE_PERL=	eg/benchmark.pl

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Readonly/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
