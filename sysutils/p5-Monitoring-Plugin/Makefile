# $NetBSD: Makefile,v 1.2 2017/08/23 17:54:52 jlam Exp $

DISTNAME=	Monitoring-Plugin-0.39
PKGNAME=    	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NI/NIERLEIN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Monitoring::Plugin
COMMENT=	family of perl modules for monitoring plugins
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor>=0.34:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Config-Tiny>=2.23:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Params-Validate>=1.26:../../devel/p5-Params-Validate
DEPENDS+=	p5-Math-Calc-Units>=1.07:../../math/p5-Math-Calc-Units

PERL5_PACKLIST=	auto/Monitoring/Plugin/.packlist

# XXX Kick can down the road and hope the developer fixes this issue.
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
