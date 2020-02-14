# $NetBSD: Makefile,v 1.20 2020/02/14 05:58:54 schmonz Exp $

DISTNAME=		Pegex-0.75
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Pegex
COMMENT=		Create equivalent parsers in lots of programming languages
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
DEPENDS+=		p5-XXX>=0.35:../../devel/p5-XXX
DEPENDS+=		p5-YAML-PP>=0.019:../../textproc/p5-YAML-PP

PERL5_PACKLIST=		auto/Pegex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
