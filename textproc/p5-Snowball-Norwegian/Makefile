# $NetBSD: Makefile,v 1.14 2020/08/31 18:11:55 wiz Exp $

DISTNAME=	Snowball-Norwegian-1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Snowball-Norwegian
COMMENT=	Porters stemming algorithm for Norwegian
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/No/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
