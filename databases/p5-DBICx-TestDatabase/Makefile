# $NetBSD: Makefile,v 1.15 2017/06/05 14:22:26 ryoon Exp $

DISTNAME=	DBICx-TestDatabase-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBICx-TestDatabase/
COMMENT=	Perl 5 module to create temporary database from a DBIx::Class::Schema
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBICx/TestDatabase/.packlist

BUILD_DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
