# $NetBSD: Makefile,v 1.25 2025/08/17 09:24:08 wiz Exp $

DISTNAME=	Class-Unload-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Unload
COMMENT=	Perl 5 module to unload a class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
# for make test
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Class/Unload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
