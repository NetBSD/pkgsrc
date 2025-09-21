# $NetBSD: Makefile,v 1.29 2025/09/21 09:52:41 wen Exp $
#

DISTNAME=	MooseX-Types-Common-0.001015
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-Common
COMMENT=	Commonly-used type constraints that do not ship with Moose by default
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.39:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types

TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/Common/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
