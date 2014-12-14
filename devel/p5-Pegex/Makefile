# $NetBSD: Makefile,v 1.2 2014/12/14 15:40:49 schmonz Exp $

DISTNAME=		Pegex-0.58
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Pegex/
COMMENT=		Create equivalent parsers in lots of programming languages
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML

PERL5_PACKLIST=		auto/Pegex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
