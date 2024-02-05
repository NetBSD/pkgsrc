# $NetBSD: Makefile,v 1.15 2024/02/05 00:50:53 schmonz Exp $

DISTNAME=	Mail-AuthenticationResults-2.20231031
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-AuthenticationResults
COMMENT=	Object Oriented Authentication-Results Headers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
TOOL_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Mail/AuthenticationResults/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
