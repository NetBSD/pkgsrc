# $NetBSD: Makefile,v 1.28 2023/06/06 12:40:48 riastradh Exp $

DISTNAME=	ExtUtils-ModuleMaker-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-ModuleMaker
COMMENT=	Perl extension for creating modules (better than h2xs)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-Copy-Recursive-Reduced-[0-9]*:../../sysutils/p5-File-Copy-Recursive-Reduced

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture
TOOL_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
TOOL_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/ExtUtils/ModuleMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
