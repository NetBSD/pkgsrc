# $NetBSD: Makefile,v 1.16 2024/11/16 12:05:32 wiz Exp $

DISTNAME=	circular-require-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/circular-require
COMMENT=	Perl5 module to detect circularity in use/require statements
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
DEPENDS+=	p5-Devel-OverrideGlobalRequire-[0-9]*:../../devel/p5-Devel-OverrideGlobalRequire

PERL5_PACKLIST=		auto/circular/require/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
