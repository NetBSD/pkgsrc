# $NetBSD: Makefile,v 1.12 2024/12/08 07:18:25 wiz Exp $

DISTNAME=	XS-Parse-Keyword-0.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/XS::Parse::Keyword
COMMENT=	XS functions to assist in parsing keyword syntax
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-CChecker-[0-9]*:../../devel/p5-ExtUtils-CChecker
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/XS/Parse/Keyword/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
