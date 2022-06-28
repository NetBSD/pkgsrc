# $NetBSD: Makefile,v 1.6 2022/06/28 11:32:14 wiz Exp $

DISTNAME=	Devel-CallChecker-0.008
PKGREVISION=	3
CATEGORIES=	devel
PKGNAME=	p5-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Z/ZE/ZEFRAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::CallChecker
COMMENT=	Custom op checking attached to subroutines
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-DynaLoader-Functions-[0-9]*:../../devel/p5-DynaLoader-Functions

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Devel/CallChecker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
