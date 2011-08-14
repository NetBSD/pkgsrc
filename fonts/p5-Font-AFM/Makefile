# $NetBSD: Makefile,v 1.17 2011/08/14 12:43:26 obache Exp $

DISTNAME=		Font-AFM-1.20
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5fon
CATEGORIES=		fonts perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Font-AFM/
COMMENT=		Perl5 modules for parsing PostScript font metrics files

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Font/AFM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
