# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:34 jlam Exp $

DISTNAME=		Locale-Maketext-Simple-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Simple interface to Locale::Maketext::Lexicon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
