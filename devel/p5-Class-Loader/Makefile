# $NetBSD: Makefile,v 1.29 2019/06/30 20:14:41 nia Exp $

DISTNAME=	Class-Loader-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	mcr@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Loader
COMMENT=	Perl5 module for module loading and on-demand object creation
LICENSE=	artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
