# $NetBSD: Makefile,v 1.17 2015/11/28 14:34:45 wen Exp $
#

DISTNAME=	Log-Report-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Report/
COMMENT=	Report a problem, pluggable handlers, and language support
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Log-Report-Optional>=0:../../devel/p5-Log-Report-Optional
BUILD_DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction

PERL5_PACKLIST=		auto/Log/Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
