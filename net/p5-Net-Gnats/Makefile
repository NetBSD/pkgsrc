# $NetBSD: Makefile,v 1.26 2019/08/11 13:22:19 wiz Exp $

DISTNAME=	Net-Gnats-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RI/RICHE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Gnats
COMMENT=	Perl interface to the gnatsd daemon
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-MakeMaker-Coverage-[0-9]*:../../devel/p5-ExtUtils-MakeMaker-Coverage
DEPENDS+=	p5-Object-Accessor-[0-9]*:../../devel/p5-Object-Accessor
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
BUILD_DEPENDS+=	p5-strictures-[0-9]*:../../devel/p5-strictures
BUILD_DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject

PERL5_PACKLIST=		auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
