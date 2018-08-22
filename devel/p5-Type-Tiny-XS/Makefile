# $NetBSD: Makefile,v 1.6 2018/08/22 09:44:54 wiz Exp $

DISTNAME=		Type-Tiny-XS-0.014
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Type-Tiny-XS/
COMMENT=		XS boost for some of Type::Tiny's type constraints
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Type/Tiny/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
