# $NetBSD: Makefile,v 1.8 2019/08/11 13:20:42 wiz Exp $

DISTNAME=		Type-Tiny-XS-0.014
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Type-Tiny-XS
COMMENT=		XS boost for some of Type::Tiny's type constraints
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Type/Tiny/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
