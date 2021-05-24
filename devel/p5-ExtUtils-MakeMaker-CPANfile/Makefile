# $NetBSD: Makefile,v 1.13 2021/05/24 19:50:38 wiz Exp $

DISTNAME=	ExtUtils-MakeMaker-CPANfile-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IS/ISHIGAKI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-MakeMaker-CPANfile
COMMENT=	Loads CPANfile & modifies parameters for WriteMakefile (Makefile.PL)
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Module-CPANfile-[0-9]*:../../devel/p5-Module-CPANfile

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/CPANfile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
