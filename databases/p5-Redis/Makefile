# $NetBSD: Makefile,v 1.3 2012/04/04 19:42:09 mishka Exp $
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
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Redis/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
