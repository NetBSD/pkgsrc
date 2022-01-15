# $NetBSD: Makefile,v 1.7 2022/01/15 11:54:57 wen Exp $

DISTNAME=	curry-2.000001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTROUT/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/curry
COMMENT=	Create automatic curried method call closures for any class or object
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/curry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
