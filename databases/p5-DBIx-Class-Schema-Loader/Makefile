# $NetBSD: Makefile,v 1.8 2010/02/22 21:24:28 sno Exp $

DISTNAME=	DBIx-Class-Schema-Loader-0.05003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Schema-Loader/
COMMENT=	Dynamic definition of a DBIx::Class::Schema
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=    user-destdir

.include "options.mk"

BUILD_DEPENDS+=	p5-DBD-SQLite>=1.12:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Kwalitee-[0-9]*:../../devel/p5-Test-Kwalitee
BUILD_DEPENDS+=	p5-Test-Simple>=0.94:../../devel/p5-Test-Simple

DEPENDS+=	p5-Carp-Clan>=0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-Accessor-Grouped>=0.09002:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-C3>=0.18:../../devel/p5-Class-C3
DEPENDS+=	p5-Class-C3-Componentised>=1.0005:../../devel/p5-Class-C3-Componentised
#DEPENDS+=	p5-Class-Data-Accessor>=0.03:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Class-Unload-[0-9]*:../../devel/p5-Class-Unload
DEPENDS+=	p5-DBIx-Class>=0.08114:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Data-Dump>=1.06:../../devel/p5-Data-Dump
DEPENDS+=	{perl>=5.8.8,p5-Digest-MD5>=2.36}:../../security/p5-Digest-MD5
DEPENDS+=	p5-File-Slurp>=9999.13:../../devel/p5-File-Slurp
#DEPENDS+=	p5-Lingua-EN-Inflect>=1.89:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-Lingua-EN-Inflect-Number>=1.1:../../textproc/p5-Lingua-EN-Inflect-Number
DEPENDS+=	{perl>=5.10,p5-PathTools>=0}:../../devel/p5-PathTools
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Text-Balanced>=0:../../textproc/p5-Text-Balanced
#DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require

# Avoid complaints if we do not have DB2, Oracle, Pg and mysql
MAKE_ENV+=	DBIC_FEATURE_NOQUESTIONS=1

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/Schema/Loader/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.560
BUILDLINK_DEPMETHOD.p5-DBI?=	build
.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
