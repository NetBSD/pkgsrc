# $NetBSD: Makefile,v 1.15 2019/07/01 21:35:34 nia Exp $

DISTNAME=	DBIx-Class-UUIDColumns-0.02006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DBIx::Class::UUIDColumns
COMMENT=	Implicit uuid columns for DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class>=0.07005:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Data-UUID>=0:../../devel/p5-Data-UUID
DEPENDS+=	p5-Class-Accessor-Grouped>=0:../../devel/p5-Class-Accessor-Grouped

BUILD_DEPENDS+= p5-DBD-SQLite>=1.11:../../databases/p5-DBD-SQLite

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/DBIx/Class/UUIDColumns/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
