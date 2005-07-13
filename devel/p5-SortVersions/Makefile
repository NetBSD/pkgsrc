# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:28 jlam Exp $
#

DISTNAME=		SortVersions-1.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sve
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		mcr@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/SortVersions/
COMMENT=		Perl5 module for sorting of revision-like numbers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sort/Versions/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
