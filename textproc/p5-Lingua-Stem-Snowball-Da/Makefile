# $NetBSD: Makefile,v 1.17 2023/07/06 09:41:40 wiz Exp $

DISTNAME=	Lingua-Stem-Snowball-Da-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-Stem-Snowball-Da
COMMENT=	Porters stemming algorithm for Denmark

REPLACE_PERL+=	stemmer.pl

PERL5_PACKLIST=	auto/Lingua/Stem/Snowball/Da/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
