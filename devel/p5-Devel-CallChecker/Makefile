# $NetBSD: Makefile,v 1.2 2020/08/31 18:07:50 wiz Exp $

DISTNAME=	Devel-CallChecker-0.008
PKGREVISION=	1
CATEGORIES=	devel
PKGNAME=	p5-${DISTNAME}
MASTER_SITES=	https://cpan.metacpan.org/authors/id/Z/ZE/ZEFRAM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/Z/ZE/ZEFRAM/
COMMENT=	Custom op checking attached to subroutines
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-DynaLoader-Functions-[0-9]*:../../devel/p5-DynaLoader-Functions

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Devel/CallChecker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
