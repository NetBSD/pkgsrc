# $NetBSD: Makefile,v 1.4 2017/06/05 14:22:26 ryoon Exp $

DISTNAME=		DBICx-Sugar-0.0100
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/I/IR/IRONCAMEL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBICx-Sugar/
COMMENT=	Just some syntax sugar for DBIx::Class
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBICx/Sugar/.packlist

BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-Test-Modern>=0:../../devel/p5-Test-Modern
BUILD_DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.07002:../../databases/p5-DBIx-Class-Schema-Loader
BUILD_DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo

DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-SQL-Translator>=0.11018:../../databases/p5-SQL-Translator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
