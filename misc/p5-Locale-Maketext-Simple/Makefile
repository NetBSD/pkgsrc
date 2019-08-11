# $NetBSD: Makefile,v 1.25 2019/08/11 13:21:58 wiz Exp $

DISTNAME=		Locale-Maketext-Simple-0.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/AUDREYT/Locale-Maketext-Simple-0.18
COMMENT=		Simple interface to Locale::Maketext::Lexicon
LICENSE=		mit

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
