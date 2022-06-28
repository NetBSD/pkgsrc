# $NetBSD: Makefile,v 1.23 2022/06/28 11:33:02 wiz Exp $

DISTNAME=	Params-ValidationCompiler-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Params::ValidationCompiler
COMMENT=	Build an optimized subroutine parameter validator once, use it forever
LICENSE=	artistic-2.0

DEPENDS+=	p5-Eval-Closure-[0-9]*:../../devel/p5-Eval-Closure
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Specio>=0.14:../../devel/p5-Specio
BUILD_DEPENDS+=	p5-Sub-Info-[0-9]*:../../devel/p5-Sub-Info
BUILD_DEPENDS+=	p5-Term-Table-[0-9]*:../../devel/p5-Term-Table
BUILD_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
BUILD_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
BUILD_DEPENDS+=	p5-Test-Without-Module-[0-9]*:../../devel/p5-Test-Without-Module

PERL5_PACKLIST=		auto/Params/ValidationCompiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
