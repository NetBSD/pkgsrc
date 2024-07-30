# $NetBSD: Makefile,v 1.27 2024/07/30 06:34:54 wen Exp $

DISTNAME=	System-Command-1.122
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=System/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/System-Command
COMMENT=	Object for running system commands
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta
TEST_DEPENDS+=	p5-Pod-Coverage-TrustPod-[0-9]*:../../textproc/p5-Pod-Coverage-TrustPod

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl # for make test
PERL5_PACKLIST=		auto/System/Command/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
