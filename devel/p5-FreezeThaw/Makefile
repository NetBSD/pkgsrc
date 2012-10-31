# $NetBSD: Makefile,v 1.23 2012/10/31 11:18:15 asau Exp $
#

DISTNAME=	FreezeThaw-0.5001
PKGNAME=	p5-FreezeThaw-0.50.01
PKGREVISION=	3
SVR4_PKGNAME=	p5frt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FreezeThaw/
COMMENT=	Converting Perl structures to strings and back
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/FreezeThaw/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
