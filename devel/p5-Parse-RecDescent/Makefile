# $NetBSD: Makefile,v 1.44 2022/06/28 11:33:03 wiz Exp $

DISTNAME=	Parse-RecDescent-1.967015
PKGNAME=	p5-${DISTNAME:S/9670/967./}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-RecDescent
COMMENT=	Perl5 module to generate recursive-descent parsers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/RecDescent/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
