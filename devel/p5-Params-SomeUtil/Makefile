# $NetBSD: Makefile,v 1.3 2026/09/27 09:55:17 wiz Exp $

DISTNAME=	Params-SomeUtil-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Params::SomeUtil
COMMENT=	Simple, compact and correct param-checking functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Params/SomeUtil/.packlist

# https://github.com/uperl/Params-SomeUtil/issues/10
EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
