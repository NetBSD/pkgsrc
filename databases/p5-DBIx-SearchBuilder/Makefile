# $NetBSD: Makefile,v 1.21 2005/03/24 17:00:14 cube Exp $
#

DISTNAME=	DBIx-SearchBuilder-1.22
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-SearchBuilder/
COMMENT=	Extension for easy SQL SELECT Statement generation

DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-DBI>=1.41:../../databases/p5-DBI
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want
DEPENDS+=	p5-Cache-Simple-TimedExpiry>=0.21:../../devel/p5-Cache-Simple-TimedExpiry

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/SearchBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
