# $NetBSD: Makefile,v 1.3 2020/07/27 02:17:50 gutteridge Exp $

DISTNAME=	Devel-CallParser-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/Z/ZE/ZEFRAM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/Z/ZE/ZEFRAM/
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
