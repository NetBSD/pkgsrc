# $NetBSD: Makefile,v 1.1.1.1 2007/01/10 21:50:51 bad Exp $
#

DISTNAME=	App-CLI-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLKAO/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://search.cpan.org/~clkao/App-CLI-0.07/
COMMENT=	Dispatcher module for command line interface programs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/App/CLI/.packlist

BUILD_DEPENDS+=	p5-ExtUtils-AutoInstall>=0.61:../../devel/p5-ExtUtils-AutoInstall
#IC5.8.8DEPENDS+=       p5-Getopt-Long>=2.35:../../devel/p5-Getopt-Long
DEPENDS+=p5-Locale-Maketext-Simple>=0.16:../../misc/p5-Locale-Maketext-Simple
#IC5.9.3
DEPENDS+=       p5-Pod-Simple>=3.02:../../textproc/p5-Pod-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
