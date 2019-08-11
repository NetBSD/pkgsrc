# $NetBSD: Makefile,v 1.30 2019/08/11 13:18:27 wiz Exp $

DISTNAME=	DBIx-Class-Fixtures-1.001039
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-Fixtures
COMMENT=	Perl 5 module to handle databases fixtures using DBIx::Class schema
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Grouped>=0.06:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Config-Any>=0.08:../../devel/p5-Config-Any
DEPENDS+=	p5-Path-Class>=0.32:../../devel/p5-Path-Class
DEPENDS+=	p5-DBIx-Class>=0.0.08102:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.07000:../../databases/p5-DBIx-Class-Schema-Loader
DEPENDS+=	p5-DBIx-Class-InflateColumn-FS>=0.01007:../../databases/p5-DBIx-Class-InflateColumn-FS
DEPENDS+=	p5-Data-Dump-Streamer>=2.05:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-Data-Visitor>=0.15:../../devel/p5-Data-Visitor
DEPENDS+=	p5-DateTime>=0.41:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-MySQL>=0.04:../../time/p5-DateTime-Format-MySQL
DEPENDS+=	p5-DateTime-Format-Pg-[0-9]*:../../time/p5-DateTime-Format-Pg
DEPENDS+=	p5-DateTime-Format-SQLite>=0.10:../../time/p5-DateTime-Format-SQLite
DEPENDS+=	p5-Devel-Confess>=0:../../devel/p5-Devel-Confess
DEPENDS+=	p5-File-Copy-Recursive>=0.35:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
DEPENDS+=	p5-Hash-Merge>=0.10:../../devel/p5-Hash-Merge
# YAML::Syck provides JSON::Syck
DEPENDS+=	p5-YAML-Syck>=1.27:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-Test-Compile>=0:../../devel/p5-Test-Compile

BUILD_DEPENDS+=	p5-Test-TempDir-Tiny>=0:../../devel/p5-Test-TempDir-Tiny
BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/Fixtures/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
