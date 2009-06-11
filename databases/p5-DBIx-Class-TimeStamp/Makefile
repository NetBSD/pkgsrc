# $NetBSD: Makefile,v 1.5 2009/06/11 12:06:10 abs Exp $

DISTNAME=	DBIx-Class-TimeStamp-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-TimeStamp/
COMMENT=	DBIx::Class component to automatically handle timestamp fields
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Install
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/TimeStamp/.packlist

BUILD_DEPENDS+=	p5-Class-Accessor-Grouped-[0-9]*:../../devel/p5-Class-Accessor-Grouped
BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-DateTime-Format-MySQL-[0-9]*:../../time/p5-DateTime-Format-MySQL
BUILD_DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
BUILD_DEPENDS+=	p5-Time-Warp-[0-9]*:../../time/p5-Time-Warp
BUILD_DEPENDS+= p5-SQL-Translator-[0-9]*:../../databases/p5-SQL-Translator

DEPENDS+=	p5-DBIx-Class-DynamicDefault-[0-9]*:../../databases/p5-DBIx-Class-DynamicDefault
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
