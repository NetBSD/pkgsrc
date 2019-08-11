# $NetBSD: Makefile,v 1.20 2019/08/11 13:23:36 wiz Exp $

DISTNAME=	Pod-Readme-v1.2.3
PKGNAME=	p5-${DISTNAME:S/v1/1/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Readme
COMMENT=	Convert POD to README file
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-CPAN-Changes>=0.30:../../devel/p5-CPAN-Changes
DEPENDS+=	p5-Moo>=1.004005:../../devel/p5-Moo
DEPENDS+=	p5-MooX-HandlesVia>=0:../../devel/p5-MooX-HandlesVia
DEPENDS+=	p5-Path-Tiny>=0.018:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Type-Tiny>=1.000000:../../devel/p5-Type-Tiny
DEPENDS+=	p5-IO-String>=0:../../devel/p5-IO-String
DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp
DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Getopt-Long-Descriptive>=0:../../devel/p5-Getopt-Long-Descriptive
BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Pod/Readme/.packlist
#PERL5_MODULE_TYPE=	Module::Build

REPLACE_PERL+=		bin/pod2readme

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
