# $NetBSD: Makefile,v 1.1.1.1 2008/08/29 20:15:22 seb Exp $

DISTNAME=	DBIx-Class-Fixtures-1.001001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Fixtures/
COMMENT=	Perl 5 module to handle databases fixtures using DBIx::Class schema

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/Fixtures/.packlist

DEPENDS+=	p5-Class-Accessor-Grouped>=0.06:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Config-Any>=0.08:../../devel/p5-Config-Any
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.04004:../../databases/p5-DBIx-Class-Schema-Loader
DEPENDS+=	p5-DBIx-Class>=0.8:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Data-Dump-Streamer>=2.05:../../devel/p5-Data-Dump-Streamer
DEPENDS+=	p5-Data-Visitor>=0.15:../../devel/p5-Data-Visitor
DEPENDS+=	p5-DateTime-Format-MySQL>=0.04:../../time/p5-DateTime-Format-MySQL
DEPENDS+=	p5-DateTime>=0.41:../../time/p5-DateTime
DEPENDS+=	p5-File-Copy-Recursive>=0.35:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Slurp>=999.13:../../devel/p5-File-Slurp
DEPENDS+=	p5-Hash-Merge>=0.10:../../devel/p5-Hash-Merge
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class
# YAML::Syck 0.88 provides JSON::Syck 0.26
DEPENDS+=	p5-YAML-Syck>=0.88:../../textproc/p5-YAML-Syck

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
