# $NetBSD: Makefile,v 1.12 2018/08/22 09:44:31 wiz Exp $

DISTNAME=		Pegex-0.64
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Pegex/
COMMENT=		Create equivalent parsers in lots of programming languages
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
DEPENDS+=		p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install

PERL5_PACKLIST=		auto/Pegex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
