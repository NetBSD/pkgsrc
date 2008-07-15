# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:42:20 abs Exp $

DISTNAME=	DBIx-Class-Schema-Loader-0.04005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Schema-Loader/
COMMENT=	Dynamic definition of a DBIx::Class::Schema

DEPENDS+=	p5-DBIx-Class>=0.05006:../../databases/p5-DBIx-Class
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Lingua-EN-Inflect>=1.89:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=   p5-Lingua-EN-Inflect-Number>=1.1:../../textproc/p5-Lingua-EN-Inflect-Number
DEPENDS+=	p5-Text-Balanced>=0:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Accessor>=0.02:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-Class-C3>=0.11:../../devel/p5-Class-C3
DEPENDS+=	p5-DBI>=1.56:../../databases/p5-DBI
DEPENDS+=	p5-DBD-SQLite>=1.12:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Carp-Clan>=0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBIx-Class>=0.06003:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Data-Dump>=1.06:../../devel/p5-Data-Dump
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector

# Avoid complaints if we do not have DB2, Oracle, Pg and mysql
MAKE_ENV+=	DBIC_FEATURE_NOQUESTIONS=1

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/Schema/Loader/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
