# $NetBSD: Makefile,v 1.24 2019/06/30 20:14:26 nia Exp $

DISTNAME=	Jifty-DBI-0.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Jifty/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Jifty-DBI
COMMENT=	Perl 5 object-relational persistence framework
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Jifty/DBI/.packlist

DEPENDS+=	p5-Cache-Memcached-[0-9]*:../../devel/p5-Cache-Memcached
DEPENDS+=	p5-Cache-Simple-TimedExpiry>=0.21:../../devel/p5-Cache-Simple-TimedExpiry
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue
DEPENDS+=	p5-Class-Trigger>=0.12:../../devel/p5-Class-Trigger
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
BUILD_DEPENDS+=	p5-DBD-SQLite>=1.14:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBIx-DBSchema>=0.34:../../databases/p5-DBIx-DBSchema
DEPENDS+=	p5-Data-Page-[0-9]*:../../devel/p5-Data-Page
DEPENDS+=	p5-DateTime-Format-ISO8601-[0-9]*:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-DateTime-Format-Strptime-[0-9]*:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-DateTime>=0.34:../../time/p5-DateTime
#DEPENDS+=	{perl>=5.8.7,p5-Encode>=2.10}:../../textproc/p5-Encode
DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=	p5-Lingua-EN-Inflect-[0-9]*:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-Object-Declare>=0.22:../../devel/p5-Object-Declare
DEPENDS+=	p5-Scalar-Defer>=0.10:../../devel/p5-Scalar-Defer
BUILD_DEPENDS+=	p5-Test-Warn>=0.10:../../devel/p5-Test-Warn
DEPENDS+=	p5-Time-Duration-Parse>=0.06:../../time/p5-Time-Duration-Parse
DEPENDS+=	p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=	p5-UNIVERSAL-require>=0.11:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
