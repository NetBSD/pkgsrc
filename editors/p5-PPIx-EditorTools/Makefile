# $NetBSD: Makefile,v 1.26 2023/07/06 09:40:31 wiz Exp $

DISTNAME=	PPIx-EditorTools-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YA/YANICK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PPIx-EditorTools
COMMENT=	Utility methods and base class for manipulating Perl via PPI
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TOOL_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
TOOL_DEPENDS+=	p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings

DEPENDS+=	p5-Class-XSAccessor>=1.02:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-PPI>=1.215:../../devel/p5-PPI
DEPENDS+=	p5-Try-Tiny>=0.11:../../devel/p5-Try-Tiny

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

PERL5_PACKLIST=		auto/PPIx/EditorTools/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
