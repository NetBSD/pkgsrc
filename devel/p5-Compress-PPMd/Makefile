# $NetBSD: Makefile,v 1.19 2024/11/16 12:03:53 wiz Exp $

DISTNAME=	Compress-PPMd-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Compress-PPMd
COMMENT=	Perl 5 module interface to the Dmitry Shkarin PPMd compression library
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c c++
PERL5_PACKLIST=		auto/Compress/PPMd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
