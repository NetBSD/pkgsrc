# $NetBSD: Makefile,v 1.16 2026/07/16 19:03:44 wiz Exp $

DISTNAME=	XS-Parse-Keyword-0.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
