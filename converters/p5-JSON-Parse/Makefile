# $NetBSD: Makefile,v 1.5 2022/09/30 23:47:31 wen Exp $

DISTNAME=	JSON-Parse-0.62
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON-Parse
COMMENT=	Read JSON into a Perl variable
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/Parse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
