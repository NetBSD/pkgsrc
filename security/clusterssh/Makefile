# $NetBSD: Makefile,v 1.19 2022/06/28 11:35:34 wiz Exp $

DISTNAME=	App-ClusterSSH-4.03_06
PKGNAME=	p5-${DISTNAME:S/_/./}
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DU/DUNCS/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/App::ClusterSSH
COMMENT=	Cluster administration tool
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-Exception-Class>=1.32:../../devel/p5-Exception-Class
DEPENDS+=	p5-Tk>=804.030:../../x11/p5-Tk
DEPENDS+=	p5-X11-Protocol>=0.56:../../x11/p5-X11-Protocol
DEPENDS+=	p5-Try-Tiny>=0.11:../../devel/p5-Try-Tiny

BUILD_DEPENDS+=	p5-CPAN-Changes>=0.400002:../../devel/p5-CPAN-Changes
BUILD_DEPENDS+=	p5-File-Which>=1.09:../../devel/p5-File-Which
BUILD_DEPENDS+=	p5-File-Slurp>=9999.19:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-Readonly>=1.03:../../devel/p5-Readonly
BUILD_DEPENDS+=	p5-Test-Differences>=0.6300:../../devel/p5-Test-Differences
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-Test-Trap>=0.2.1:../../devel/p5-Test-Trap
BUILD_DEPENDS+=	p5-Test-Pod>=1.45:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-DistManifest>=1.012:../../devel/p5-Test-DistManifest
BUILD_DEPENDS+=	xterm>=322:../../x11/xterm

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/App/ClusterSSH/.packlist
USE_LANGUAGES=		# none
USE_TOOLS+=		perl

REPLACE_PERL+=		bin_PL/ccon
REPLACE_PERL+=		bin_PL/crsh
REPLACE_PERL+=		bin_PL/cssh
REPLACE_PERL+=		bin_PL/ctel
REPLACE_PERL+=		t/external_cluster_command

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
