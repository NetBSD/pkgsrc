# $NetBSD: Makefile,v 1.24 2013/07/03 13:41:10 sno Exp $

DISTNAME=	JSON-XS-2.34
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
