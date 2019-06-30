# $NetBSD: Makefile,v 1.20 2019/06/30 20:14:28 nia Exp $

DISTNAME=	Search-QueryParser-SQL-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Search-QueryParser-SQL
COMMENT=	Perl module to turn free-text queries into SQL WHERE clauses
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-Search-QueryParser>=0.93:../../databases/p5-Search-QueryParser

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Search/QueryParser/SQL/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
