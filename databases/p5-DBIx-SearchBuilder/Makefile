# $NetBSD: Makefile,v 1.67 2023/11/01 19:49:10 markd Exp $

DISTNAME=	DBIx-SearchBuilder-1.78
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-SearchBuilder
COMMENT=	Extension for easy SQL SELECT Statement generation
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

DEPENDS+=	p5-Cache-Simple-TimedExpiry>=0.21:../../devel/p5-Cache-Simple-TimedExpiry
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
#DEPENDS+=	{perl>=5.8.3,p5-Encode>=1.99}:../../textproc/p5-Encode
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

# Recommented dependencies
DEPENDS+=	p5-capitalization>=0.03nb1:../../devel/p5-capitalization
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBIx-DBSchema-[0-9]*:../../databases/p5-DBIx-DBSchema

PERL5_PACKLIST=		auto/DBIx/SearchBuilder/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
