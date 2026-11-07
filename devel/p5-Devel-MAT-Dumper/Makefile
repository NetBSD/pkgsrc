# $NetBSD: Makefile,v 1.11 2026/11/07 08:58:38 wen Exp $

DISTNAME=	Devel-MAT-Dumper-0.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::MAT::Dumper
COMMENT=	Write a heap dump file for later analysis
LICENSE=	${PERL5_LICENSE}

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

PERL5_PACKLIST=		auto/Devel/MAT/Dumper/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
