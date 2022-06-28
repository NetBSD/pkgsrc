# $NetBSD: Makefile,v 1.18 2022/06/28 11:36:26 wiz Exp $

DISTNAME=		String-ToIdentifier-EN-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-ToIdentifier-EN
COMMENT=		Convert Strings to English Program Identifiers
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Lingua-EN-Inflect-Phrase>=0.07:../../textproc/p5-Lingua-EN-Inflect-Phrase
DEPENDS+=		p5-Text-Unidecode>=0.04:../../textproc/p5-Text-Unidecode
DEPENDS+=		p5-namespace-clean>=0.20:../../devel/p5-namespace-clean

PERL5_PACKLIST=		auto/String/ToIdentifier/EN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
