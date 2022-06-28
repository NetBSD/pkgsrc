# $NetBSD: Makefile,v 1.16 2022/06/28 11:30:52 wiz Exp $

DISTNAME=	Archive-Any-Lite-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Archive-Any-Lite
COMMENT=	Simple CPAN package extractor
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-CPANfile>=0:../../devel/p5-Module-CPANfile
DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile>=0:../../devel/p5-ExtUtils-MakeMaker-CPANfile
# for make test
BUILD_DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
BUILD_DEPENDS+=	p5-Test-UseAllModules-[0-9]*:../../devel/p5-Test-UseAllModules

PERL5_PACKLIST=	auto/Archive/Any/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
