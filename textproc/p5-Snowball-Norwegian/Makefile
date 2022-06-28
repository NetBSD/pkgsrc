# $NetBSD: Makefile,v 1.17 2022/06/28 11:36:24 wiz Exp $

DISTNAME=	Snowball-Norwegian-1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASKSH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Snowball-Norwegian
COMMENT=	Porters stemming algorithm for Norwegian
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL=	bin/stemmer-no.pl

PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/No/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
