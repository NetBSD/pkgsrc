# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:34 asau Exp $
#

DISTNAME=	Redis-1.951
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5rds
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/ME/MELO/}

MAINTAINER=	tnozaki@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Redis/
COMMENT=	Perl binding for Redis database
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Redis/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
