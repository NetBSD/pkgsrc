# $NetBSD: Makefile,v 1.25 2019/06/30 20:14:33 nia Exp $

DISTNAME=	B-Hooks-EndOfScope-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Hooks-EndOfScope
COMMENT=	Perl 5 module to execute code after a scope finished compilation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-Progressive>=0.001006:../../devel/p5-Sub-Exporter-Progressive
DEPENDS+=	p5-Variable-Magic>=0.48:../../devel/p5-Variable-Magic
DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

#USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/B/Hooks/EndOfScope/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
