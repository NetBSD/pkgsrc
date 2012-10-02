# $NetBSD: Makefile,v 1.7 2012/10/02 21:25:28 asau Exp $

DISTNAME=	DBICx-Deploy-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBICx-Deploy/
COMMENT=	Perl 5 module to deploy a a DBIx::Class schema

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBICx/Deploy/.packlist

BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator

REPLACE_PERL+=	bin/dbicdeploy

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
