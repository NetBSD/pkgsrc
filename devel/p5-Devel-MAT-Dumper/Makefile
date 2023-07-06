# $NetBSD: Makefile,v 1.2 2023/07/06 09:39:02 wiz Exp $

DISTNAME=	Devel-MAT-Dumper-0.47
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::MAT::Dumper
COMMENT=	Write a heap dump file for later analysis
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-Commandable-[0-9]*:../../devel/p5-Commandable
#TEST_DEPENDS+=	p5-Test-Identity-[0-9]*:../../devel/p5-Test-Identity

PERL5_PACKLIST=		auto/Devel/MAT/Dumper/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
