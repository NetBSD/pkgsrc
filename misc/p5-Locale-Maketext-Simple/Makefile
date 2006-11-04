# $NetBSD: Makefile,v 1.7 2006/11/04 11:54:39 obache Exp $

DISTNAME=		Locale-Maketext-Simple-0.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~audreyt/Locale-Maketext-Simple/
COMMENT=		Simple interface to Locale::Maketext::Lexicon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
