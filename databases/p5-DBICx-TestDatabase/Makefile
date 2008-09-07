# $NetBSD: Makefile,v 1.1.1.1 2008/09/07 20:40:52 seb Exp $

DISTNAME=	DBICx-TestDatabase-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBICx-TestDatabase/
COMMENT=	Perl 5 module to create temporary database from a DBIx::Class::Schema

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBICx/TestDatabase/.packlist

BUILD_DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok
DEPENDS+=	p5-DBD-SQLite:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
