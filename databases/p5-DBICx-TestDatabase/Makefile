# $NetBSD: Makefile,v 1.23 2022/06/28 11:31:23 wiz Exp $

DISTNAME=	DBICx-TestDatabase-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBICx-TestDatabase
COMMENT=	Perl 5 module to create temporary database from a DBIx::Class::Schema
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/DBICx/TestDatabase/.packlist

BUILD_DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
