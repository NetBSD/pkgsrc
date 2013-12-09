# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:46 obache Exp $
#

DISTNAME=	TAP-Harness-Archive-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=TAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/TAP-Harness-Archive/
COMMENT=	Create an archive of TAP test results
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.1,p5-Test-Harness>=3.05}:../../devel/p5-Test-Harness
DEPENDS+=	p5-YAML-Tiny>=0:../../textproc/p5-YAML-Tiny

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TAP/Harness/Archive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
