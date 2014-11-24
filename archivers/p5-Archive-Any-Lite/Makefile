# $NetBSD: Makefile,v 1.5 2014/11/24 11:55:29 mef Exp $

DISTNAME=	Archive-Any-Lite-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Any-Lite/
COMMENT=	Simple CPAN package extractor
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-CPANfile>=0:../../devel/p5-Module-CPANfile
DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile>=0:../../devel/p5-ExtUtils-MakeMaker-CPANfile

PERL5_PACKLIST=	auto/Archive/Any/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
