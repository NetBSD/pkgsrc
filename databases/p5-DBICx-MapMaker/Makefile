# $NetBSD: Makefile,v 1.15 2017/06/05 14:22:26 ryoon Exp $

DISTNAME=	DBICx-MapMaker-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBICx-MapMaker/
COMMENT=	Perl 5 module to automatically create a DBIx::Class mapping table

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBICx/MapMaker/.packlist

BUILD_DEPENDS+=	p5-DBICx-TestDatabase-[0-9]*:../../databases/p5-DBICx-TestDatabase
BUILD_DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
