# $NetBSD: Makefile,v 1.16 2004/04/11 16:12:40 recht Exp $
#

DISTNAME=	DBIx-SearchBuilder-0.99
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Extension for easy SQL SELECT Statement generation

DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-DBI>=1.41:../../databases/p5-DBI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/SearchBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
