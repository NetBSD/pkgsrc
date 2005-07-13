# $NetBSD: Makefile,v 1.7 2005/07/13 18:01:34 jlam Exp $
#

DISTNAME=		Locale-Maketext-Lexicon-0.47
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://search.cpan.org/~autrijus/Locale-Maketext-Lexicon/
COMMENT=		Use other catalog formats in Maketext

DEPENDS+=		{perl>=5.8.0,perl-thread>=5.8.0,p5-Locale-Maketext-[0-8]*}:../../misc/p5-Locale-Maketext

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Lexicon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
