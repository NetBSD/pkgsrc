# $NetBSD: Makefile,v 1.8 2012/10/02 21:25:35 asau Exp $

DISTNAME=	Search-QueryParser-SQL-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Search-QueryParser-SQL/
COMMENT=	Perl module to turn free-text queries into SQL WHERE clauses
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-Search-QueryParser>=0.93:../../databases/p5-Search-QueryParser/

PERL5_PACKLIST=	auto/Search/QueryParser/SQL/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
