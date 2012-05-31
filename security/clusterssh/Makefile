# $NetBSD: Makefile,v 1.1.1.1 2012/05/31 16:54:10 imil Exp $
#

DISTNAME=	App-ClusterSSH-4.01_01
PKGNAME=	p5-${DISTNAME:S/_/./}
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DU/DUNCS/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DU/DUNCS/
COMMENT=	Cluster administration tool
LICENSE=	gnu-gpl-v1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Exception-Class>=1.32:../../devel/p5-Exception-Class
DEPENDS+=	p5-Tk>=804.030:../../x11/p5-Tk
DEPENDS+=	p5-X11-Protocol>=0.56:../../x11/p5-X11-Protocol
DEPENDS+=	p5-Try-Tiny>=0.11:../../devel/p5-Try-Tiny

BUILD_DEPENDS+=	p5-File-Which>=1.09:../../devel/p5-File-Which
BUILD_DEPENDS+=	p5-Readonly>=1.03:../../devel/p5-Readonly
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-Test-Trap>=0.2.1:../../devel/p5-Test-Trap
BUILD_DEPENDS+=	p5-Test-Pod>=1.45:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-DistManifest>=1.012:../../devel/p5-Test-DistManifest

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/App/ClusterSSH/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
