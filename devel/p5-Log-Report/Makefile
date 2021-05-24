# $NetBSD: Makefile,v 1.37 2021/05/24 19:50:59 wiz Exp $

DISTNAME=	Log-Report-1.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Report
COMMENT=	Report a problem, pluggable handlers, and language support
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Devel-GlobalDestruction>=0.09:../../devel/p5-Devel-GlobalDestruction

# Followng two to be source expanded at test time
TEST_DEPENDS+=	p5-Log-Report-Optional>=1.03:../../devel/p5-Log-Report-Optional
TEST_DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious
TEST_DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch
TEST_DEPENDS+=	p5-Dancer2-[0-9]*:../../www/p5-Dancer2

PERL5_PACKLIST=		auto/Log/Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
