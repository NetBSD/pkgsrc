# $NetBSD: Makefile,v 1.35 2018/08/22 09:45:45 wiz Exp $
#

DISTNAME=		Locale-Maketext-Lexicon-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext-Lexicon/
COMMENT=		Use other catalog formats in Maketext
LICENSE=		mit

#DEPENDS+=		{perl>=5.8.0,p5-Locale-Maketext-[0-8]*}:../../misc/p5-Locale-Maketext

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Lexicon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
