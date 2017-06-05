# $NetBSD: Makefile,v 1.24 2017/06/05 14:23:12 ryoon Exp $
#

DISTNAME=	Log-Report-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
