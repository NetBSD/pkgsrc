# $NetBSD: Makefile,v 1.3 2019/07/01 21:35:36 nia Exp $

DISTNAME=	Devel-OverrideGlobalRequire-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5 net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DA/DAGOLDEN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-OverrideGlobalRequire
COMMENT=	Perl 5 package that overrides CORE::GLOBAL::require safely
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Devel/OverrideGlobalRequire/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
