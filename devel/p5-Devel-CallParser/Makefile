# $NetBSD: Makefile,v 1.8 2022/06/28 11:32:14 wiz Exp $

DISTNAME=	Devel-CallParser-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Z/ZE/ZEFRAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::CallParser
COMMENT=	Custom parsing attached to subroutines
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-CallChecker-[0-9]*:../../devel/p5-Devel-CallChecker
DEPENDS+=	p5-DynaLoader-Functions-[0-9]*:../../devel/p5-DynaLoader-Functions

TEST_DEPENDS+=	p5-Data-Alias-[0-9]*:../../devel/p5-Data-Alias
TEST_DEPENDS+=	p5-Devel-Declare-[0-9]*:../../devel/p5-Devel-Declare

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Devel/CallParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
