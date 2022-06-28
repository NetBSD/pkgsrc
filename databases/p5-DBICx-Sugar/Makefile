# $NetBSD: Makefile,v 1.12 2022/06/28 11:31:23 wiz Exp $

DISTNAME=	DBICx-Sugar-0.0200
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/I/IR/IRONCAMEL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBICx-Sugar
COMMENT=	Just some syntax sugar for DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

BUILD_DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-Test-API-[0-9]*:../../devel/p5-Test-API
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Modern-[0-9]*:../../devel/p5-Test-Modern
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-DBIx-Class-Schema-Loader-[0-9]*:../../databases/p5-DBIx-Class-Schema-Loader
BUILD_DEPENDS+=	p5-MooseX-Types-LoadableClass-[0-9]*:../../devel/p5-MooseX-Types-LoadableClass

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBICx/Sugar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
