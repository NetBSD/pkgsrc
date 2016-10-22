# $NetBSD: Makefile,v 1.22 2016/10/22 07:10:08 wen Exp $
#

DISTNAME=	Log-Report-1.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Report/
COMMENT=	Report a problem, pluggable handlers, and language support
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Log-Report-Optional>=1.02:../../devel/p5-Log-Report-Optional
BUILD_DEPENDS+=	p5-Devel-GlobalDestruction>=0.09:../../devel/p5-Devel-GlobalDestruction
# for make test ( and optional)
BUILD_DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious

PERL5_PACKLIST=		auto/Log/Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
