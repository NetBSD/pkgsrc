# $NetBSD: Makefile,v 1.2 2016/10/01 12:54:08 wiz Exp $

DISTNAME=	Params-ValidationCompiler-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
#BUILD_DEPENDS+=	p5-Test2-Bundle-Extended-[0-9]*:../../devel/p5-Test2-Bundle-Extended
#BUILD_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
#BUILD_DEPENDS+=	p5-Test2-Require-Module-[0-9]*:../../devel/p5-Test2-Require-Module
#BUILD_DEPENDS+=	p5-Test-More>=1.302015:../../devel/p5-Test-More

PERL5_PACKLIST=		auto/Params/ValidationCompiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
