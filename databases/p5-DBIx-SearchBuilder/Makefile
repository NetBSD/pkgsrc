# $NetBSD: Makefile,v 1.32.8.1 2008/04/30 11:25:39 rtr Exp $
#

DISTNAME=	DBIx-SearchBuilder-1.53
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-SearchBuilder/
COMMENT=	Extension for easy SQL SELECT Statement generation

BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-capitalization>=0.03nb1:../../devel/p5-capitalization
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-DBI>=1.41:../../databases/p5-DBI
DEPENDS+=	p5-DBIx-DBSchema-[0-9]*:../../databases/p5-DBIx-DBSchema
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want
DEPENDS+=	p5-Cache-Simple-TimedExpiry>=0.21:../../devel/p5-Cache-Simple-TimedExpiry

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/SearchBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
