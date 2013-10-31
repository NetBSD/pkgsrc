# $NetBSD: Makefile,v 1.6 2013/10/31 08:24:30 wen Exp $

DISTNAME=	DBIx-Class-Helpers-2.019000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Helpers/
COMMENT=	Perl5 modules to simplify the common case stuff for DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan>=6.04:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBIx-Class>=0.08127:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Candy>=0.001003:../../databases/p5-DBIx-Class-Candy
DEPENDS+=	p5-Lingua-EN-Inflect-[0-9]*:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-String-CamelCase-[0-9]*:../../textproc/p5-String-CamelCase
DEPENDS+=	p5-Sub-Exporter-Progressive-[0-9]*:../../devel/p5-Sub-Exporter-Progressive
DEPENDS+=	p5-namespace-clean>=0.23:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-DateTime-Format-SQLite>=0:../../time/p5-DateTime-Format-SQLite
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DBIx/Class/Helpers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
