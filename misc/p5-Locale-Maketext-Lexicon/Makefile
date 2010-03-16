# $NetBSD: Makefile,v 1.20 2010/03/16 22:55:46 sno Exp $
#

DISTNAME=		Locale-Maketext-Lexicon-0.79
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext-Lexicon/
COMMENT=		Use other catalog formats in Maketext
LICENSE=		mit

DEPENDS+=		{perl>=5.8.0,p5-Locale-Maketext-[0-8]*}:../../misc/p5-Locale-Maketext

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Lexicon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
