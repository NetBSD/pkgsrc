# $NetBSD: Makefile,v 1.4 2016/11/16 10:23:54 wiz Exp $

DISTNAME=	Params-ValidationCompiler-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/
COMMENT=	Build an optimized subroutine parameter validator once, use it forever
LICENSE=	artistic-2.0

DEPENDS+=	p5-Eval-Closure-[0-9]*:../../devel/p5-Eval-Closure
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Specio>=0.14:../../devel/p5-Specio
BUILD_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
BUILD_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
BUILD_DEPENDS+=	p5-Test-Without-Module-[0-9]*:../../devel/p5-Test-Without-Module

PERL5_PACKLIST=		auto/Params/ValidationCompiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
