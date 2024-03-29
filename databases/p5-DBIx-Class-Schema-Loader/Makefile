# $NetBSD: Makefile,v 1.45 2023/07/06 09:38:24 wiz Exp $

DISTNAME=	DBIx-Class-Schema-Loader-0.07049
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-Schema-Loader
COMMENT=	Dynamic definition of a DBIx::Class::Schema
LICENSE=	${PERL5_LICENSE}

.include "options.mk"

TOOL_DEPENDS+=		p5-Config-Any-[0-9]*:../../devel/p5-Config-Any
TOOL_DEPENDS+=		p5-Config-General-[0-9]*:../../devel/p5-Config-General
TOOL_DEPENDS+=		p5-DBD-SQLite>=1.29:../../databases/p5-DBD-SQLite
#TOOL_DEPENDS+=	{perl>=5.10.1,p5-File-Path>=2.07}:../../devel/p5-File-Path
TOOL_DEPENDS+=		p5-Moose>=1.1200:../../devel/p5-Moose
TOOL_DEPENDS+=		p5-MooseX-MarkAsMethods>=0.13:../../devel/p5-MooseX-MarkAsMethods
TOOL_DEPENDS+=		p5-MooseX-NonMoose>=0.16:../../devel/p5-MooseX-NonMoose
#TOOL_DEPENDS+=	{perl>=5.18.0,p5-Pod-Simple>=3.22}:../../textproc/p5-Pod-Simple
TOOL_DEPENDS+=		p5-Text-Unidecode>=0:../../textproc/p5-Text-Unidecode
TOOL_DEPENDS+=		p5-Test-Exception>=0.31:../../devel/p5-Test-Exception
# TOOL_DEPENDS+=	p5-Test-Kwalitee-[0-9]*:../../devel/p5-Test-Kwalitee
#TOOL_DEPENDS+=	{perl>=5.12.0,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple
TOOL_DEPENDS+=		p5-Test-Warn>=0.21:../../devel/p5-Test-Warn
TOOL_DEPENDS+=		p5-namespace-autoclean>=0.09:../../devel/p5-namespace-autoclean

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-Accessor-Grouped>=0.10008:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-C3-Componentised>=1.0008:../../devel/p5-Class-C3-Componentised
DEPENDS+=	p5-Class-Inspector>=1.27:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Class-Unload>=0.07:../../devel/p5-Class-Unload
DEPENDS+=	p5-curry>=1.000000:../../devel/p5-curry
DEPENDS+=	p5-DBIx-Class>=0.08127:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Data-Dump>=1.06:../../devel/p5-Data-Dump
#DEPENDS+=	{perl>=5.8.8,p5-Digest-MD5>=2.36}:../../security/p5-Digest-MD5
DEPENDS+=	p5-File-Slurp>=9999.13:../../devel/p5-File-Slurp
DEPENDS+=	p5-Hash-Merge>=0.12:../../devel/p5-Hash-Merge
DEPENDS+=	p5-Lingua-EN-Inflect-Number>=1.1:../../textproc/p5-Lingua-EN-Inflect-Number
DEPENDS+=	p5-Lingua-EN-Inflect-Phrase>=0.15:../../textproc/p5-Lingua-EN-Inflect-Phrase
DEPENDS+=	p5-Lingua-EN-Tagger>=0.23:../../textproc/p5-Lingua-EN-Tagger
DEPENDS+=	p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat
#DEPENDS+=	{perl>=5.10,p5-PathTools-[0-9]*}:../../devel/p5-PathTools
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Scope-Guard>=0.20:../../devel/p5-Scope-Guard
DEPENDS+=	p5-String-CamelCase>=0.02:../../textproc/p5-String-CamelCase
DEPENDS+=	p5-String-ToIdentifier-EN>=0.05:../../textproc/p5-String-ToIdentifier-EN
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-clean>=0.23:../../devel/p5-namespace-clean

# for make test
TOOL_DEPENDS+=	p5-DBD-SQLite2-[0-9]*:../../databases/p5-DBD-SQLite2
TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TOOL_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

# Avoid complaints if we do not have DB2, Oracle, Pg and mysql
MAKE_ENV+=	DBIC_FEATURE_NOQUESTIONS=1

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Class/Schema/Loader/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.560
BUILDLINK_DEPMETHOD.p5-DBI?=	build
.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
