# $NetBSD: Makefile,v 1.22 2022/06/28 11:33:17 wiz Exp $

DISTNAME=	TAP-Harness-Archive-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=TAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TAP-Harness-Archive
COMMENT=	Create an archive of TAP test results
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.1,p5-Test-Harness>=3.05}:../../devel/p5-Test-Harness
DEPENDS+=	p5-YAML-Tiny>=0:../../textproc/p5-YAML-Tiny

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TAP/Harness/Archive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
