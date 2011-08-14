# $NetBSD: Makefile,v 1.13 2011/08/14 13:45:16 obache Exp $
#

DISTNAME=		Locale-Maketext-Fuzzy-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext-Fuzzy/
COMMENT=		Maketext from already interpolated strings

DEPENDS+=		{perl>=5.8.0,p5-Locale-Maketext-[0-9]*}:../../misc/p5-Locale-Maketext

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Locale/Maketext/Fuzzy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
