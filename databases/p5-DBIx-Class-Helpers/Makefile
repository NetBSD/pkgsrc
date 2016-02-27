# $NetBSD: Makefile,v 1.17 2016/02/27 08:01:44 wen Exp $

DISTNAME=	DBIx-Class-Helpers-2.032000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Helpers/
COMMENT=	Perl5 modules to simplify the common case stuff for DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan>=6.04:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBIx-Class>=0.082600:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Candy>=0.003001:../../databases/p5-DBIx-Class-Candy
DEPENDS+=	p5-DBIx-Introspector>=0.001002:../../databases/p5-DBIx-Introspector
DEPENDS+=	p5-Lingua-EN-Inflect-[0-9]*:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-Safe-Isa>=0:../../devel/p5-Safe-Isa
DEPENDS+=	p5-String-CamelCase-[0-9]*:../../textproc/p5-String-CamelCase
DEPENDS+=	p5-Sub-Exporter-Progressive>=0.001006:../../devel/p5-Sub-Exporter-Progressive
DEPENDS+=	p5-namespace-clean>=0.23:../../devel/p5-namespace-clean
DEPENDS+=	p5-Role-Tiny>=0:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Text-Brew>=0:../../textproc/p5-Text-Brew
DEPENDS+=	p5-Try-Tiny>=0:../../devel/p5-Try-Tiny

BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-DateTime-TimeZone>=0:../../time/p5-DateTime-TimeZone
BUILD_DEPENDS+=	p5-DateTime-Format-SQLite>=0:../../time/p5-DateTime-Format-SQLite
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Roo>=1.003:../../devel/p5-Test-Roo
BUILD_DEPENDS+=	p5-DateTime-Format-Strptime>=0:../../time/p5-DateTime-Format-Strptime
BUILD_DEPENDS+=	p5-aliased>=0.34:../../devel/p5-aliased

PERL5_PACKLIST=		auto/DBIx/Class/Helpers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
