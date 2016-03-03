# $NetBSD: Makefile,v 1.28 2016/03/03 12:49:25 wiz Exp $

DISTNAME=	JSON-XS-3.02
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-XS/
COMMENT=	JSON serialising/deserialising, done correctly and fast
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense>=0:../../devel/p5-common-sense
DEPENDS+=	p5-Canary-Stability>=0:../../devel/p5-Canary-Stability
DEPENDS+=	p5-Types-Serialiser>=0:../../devel/p5-Types-Serialiser

PERL5_PACKLIST=	auto/JSON/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
