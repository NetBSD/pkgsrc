# $NetBSD: Makefile,v 1.15 2023/07/06 09:39:42 wiz Exp $
#

DISTNAME=	MooseX-Types-LogAny-0.001003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-LogAny
COMMENT=	Moose Types for Log::Any
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types

TOOL_DEPENDS+=	p5-Class-Load>=0.20:../../devel/p5-Class-Load
TOOL_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/LogAny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
