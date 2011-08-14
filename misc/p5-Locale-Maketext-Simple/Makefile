# $NetBSD: Makefile,v 1.13 2011/08/14 13:45:16 obache Exp $

DISTNAME=		Locale-Maketext-Simple-0.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~audreyt/Locale-Maketext-Simple/
COMMENT=		Simple interface to Locale::Maketext::Lexicon
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
