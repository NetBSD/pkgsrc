# $NetBSD: Makefile,v 1.22 2017/06/05 14:24:15 ryoon Exp $

DISTNAME=		Locale-Maketext-Simple-0.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~audreyt/Locale-Maketext-Simple/
COMMENT=		Simple interface to Locale::Maketext::Lexicon
LICENSE=		mit

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
