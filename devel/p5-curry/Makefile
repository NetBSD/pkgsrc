# $NetBSD: Makefile,v 1.12 2026/07/16 19:03:46 wiz Exp $

DISTNAME=	curry-2.000001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTROUT/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/curry
COMMENT=	Create automatic curried method call closures for any class or object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/curry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
