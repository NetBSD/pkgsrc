# $NetBSD: Makefile,v 1.21 2012/10/03 00:20:13 asau Exp $

DISTNAME=	JSON-XS-2.33
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-XS/
COMMENT=	JSON serialising/deserialising, done correctly and fast
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

PERL5_PACKLIST=	auto/JSON/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
