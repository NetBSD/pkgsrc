# $NetBSD: Makefile,v 1.7 2013/12/09 14:17:43 obache Exp $

DISTNAME=	BackPAN-Index-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BackPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BackPAN-Index/
COMMENT=	Perl 5 module providing an interface to the BackPAN index
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/BackPAN/Index/.packlist

REPLACE_PERL+=	create_backpan_index.pl

BUILD_DEPENDS+=	p5-Test-Compile>=0.11:../../devel/p5-Test-Compile
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.90}:../../devel/p5-Test-Simple
DEPENDS+=	p5-App-Cache>=0.37:../../devel/p5-App-Cache
DEPENDS+=	p5-CLASS>=1.00:../../devel/p5-CLASS
DEPENDS+=	p5-CPAN-DistnameInfo>=0.09:../../devel/p5-CPAN-DistnameInfo
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBD-SQLite>=1.25:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBIx-Class>=0.08109:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.05003:../../databases/p5-DBIx-Class-Schema-Loader
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Path-Class>=0.17:../../devel/p5-Path-Class
DEPENDS+=	{perl>=5.10.1,p5-autodie-[0-9]*}:../../devel/p5-autodie
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
