# $NetBSD: Makefile,v 1.2 2023/06/30 11:43:03 wen Exp $

DISTNAME=	XS-Parse-Keyword-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/XS::Parse::Keyword
COMMENT=	XS functions to assist in parsing keyword syntax
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-CChecker-[0-9]*:../../devel/p5-ExtUtils-CChecker

PERL5_PACKLIST=		auto/XS/Parse/Keyword/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
