# $NetBSD: Makefile,v 1.26 2023/07/06 09:39:49 wiz Exp $

DISTNAME=	Params-ValidationCompiler-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Params::ValidationCompiler
COMMENT=	Build an optimized subroutine parameter validator once, use it forever
LICENSE=	artistic-2.0

DEPENDS+=	p5-Eval-Closure-[0-9]*:../../devel/p5-Eval-Closure
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Specio>=0.14:../../devel/p5-Specio
TOOL_DEPENDS+=	p5-Sub-Info-[0-9]*:../../devel/p5-Sub-Info
TOOL_DEPENDS+=	p5-Term-Table-[0-9]*:../../devel/p5-Term-Table
TOOL_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TOOL_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
TOOL_DEPENDS+=	p5-Test-Without-Module-[0-9]*:../../devel/p5-Test-Without-Module

PERL5_PACKLIST=		auto/Params/ValidationCompiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
