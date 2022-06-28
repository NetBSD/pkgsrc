# $NetBSD: Makefile,v 1.26 2022/06/28 11:31:10 wiz Exp $

DISTNAME=	JSON-MaybeXS-1.004002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON-MaybeXS
COMMENT=	Use Cpanel::JSON::XS with a fallback to JSON::PP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cpanel-JSON-XS-[0-9]*:../../converters/p5-Cpanel-JSON-XS
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs

PERL5_PACKLIST=		auto/JSON/MaybeXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
