# $NetBSD: Makefile,v 1.20 2022/06/28 11:35:47 wiz Exp $

DISTNAME=	Digest-SHA3-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-SHA3
COMMENT=	Perl5 module for SHA-3
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Digest/SHA3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
