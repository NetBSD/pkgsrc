# $NetBSD: Makefile,v 1.13 2022/06/28 11:33:14 wiz Exp $

DISTNAME=	Stream-Buffered-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Stream/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Stream-Buffered
COMMENT=	Perl extension for temporary buffer to save bytes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Stream/Buffered/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
