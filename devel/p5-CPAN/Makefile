# $NetBSD: Makefile,v 1.6 2011/08/10 09:52:50 adam Exp $

DISTNAME=	CPAN-1.9800
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AN/ANDK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN/
COMMENT=	Perl module to query, download and build perl modules from CPAN sites
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
MAKE_PARAMS+=		verbose
PERL5_PACKLIST=		auto/CPAN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
