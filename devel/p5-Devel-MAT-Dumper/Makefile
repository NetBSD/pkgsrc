# $NetBSD: Makefile,v 1.5 2024/03/12 07:55:43 wiz Exp $

DISTNAME=	Devel-MAT-Dumper-0.48
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::MAT::Dumper
COMMENT=	Write a heap dump file for later analysis
LICENSE=	${PERL5_LICENSE}

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

#DEPENDS+=	p5-Commandable-[0-9]*:../../devel/p5-Commandable
#TEST_DEPENDS+=	p5-Test-Identity-[0-9]*:../../devel/p5-Test-Identity

PERL5_PACKLIST=		auto/Devel/MAT/Dumper/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
