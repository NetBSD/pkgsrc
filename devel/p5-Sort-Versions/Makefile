# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:36 obache Exp $
#

DISTNAME=		Sort-Versions-1.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5sve
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sort-Versions/
COMMENT=		Perl5 module for sorting of revision-like numbers

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sort/Versions/.packlist

CONFLICTS+=		p5-SortVersion-[0-9]*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
