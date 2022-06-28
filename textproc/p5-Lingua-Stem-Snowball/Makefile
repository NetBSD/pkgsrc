# $NetBSD: Makefile,v 1.22 2022/06/28 11:36:19 wiz Exp $

DISTNAME=	Lingua-Stem-Snowball-0.952
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-Stem-Snowball
COMMENT=	Lingua::Stem::Snowball - Perl interface to Snowball stemmers

PERL5_MODULE_TYPE=	Module::Build
PERL5_REQD+=		5.8.0
PERL5_PACKLIST=		auto/Lingua/Stem/Snowball/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
