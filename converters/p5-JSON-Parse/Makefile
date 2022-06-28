# $NetBSD: Makefile,v 1.4 2022/06/28 11:31:10 wiz Exp $

DISTNAME=	JSON-Parse-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON-Parse
COMMENT=	Read JSON into a Perl variable
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/Parse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
