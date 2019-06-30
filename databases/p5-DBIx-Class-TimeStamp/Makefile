# $NetBSD: Makefile,v 1.22 2019/06/30 20:14:24 nia Exp $

DISTNAME=	DBIx-Class-TimeStamp-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-TimeStamp
COMMENT=	DBIx::Class component to automatically handle timestamp fields
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Install::Bundled
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/TimeStamp/.packlist

BUILD_DEPENDS+=	p5-Class-Accessor-Grouped-[0-9]*:../../devel/p5-Class-Accessor-Grouped
BUILD_DEPENDS+=	p5-DateTime-Format-MySQL-[0-9]*:../../time/p5-DateTime-Format-MySQL
BUILD_DEPENDS+=	p5-DateTime-Format-SQLite-[0-9]*:../../time/p5-DateTime-Format-SQLite
#BUILD_DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
BUILD_DEPENDS+=	p5-Time-Warp-[0-9]*:../../time/p5-Time-Warp

DEPENDS+=	p5-DBIx-Class>=0.08009:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-DynamicDefault>=0.03:../../databases/p5-DBIx-Class-DynamicDefault
DEPENDS+=	p5-DateTime>=0.5500:../../time/p5-DateTime

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
