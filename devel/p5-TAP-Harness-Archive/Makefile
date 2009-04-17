# $NetBSD: Makefile,v 1.1.1.1 2009/04/17 16:46:55 he Exp $
#

DISTNAME=	TAP-Harness-Archive-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=TAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/TAP-Harness-Archive/
COMMENT=	Create an archive of TAP test results

DEPENDS+=	p5-Test-Harness>=3.05:../../devel/p5-Test-Harness
DEPENDS+=	p5-YAML-Tiny>=0:../../textproc/p5-YAML-Tiny

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TAP/Harness/Archive/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
