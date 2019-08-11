# $NetBSD: Makefile,v 1.10 2019/08/11 13:22:50 wiz Exp $

DISTNAME=	Bytes-Random-Secure-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bytes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Bytes-Random-Secure
COMMENT=	Perl extension to generate cryptographically-secure random bytes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-Random-ISAAC>=0:../../math/p5-Math-Random-ISAAC
DEPENDS+=	p5-Crypt-Random-Seed>=0:../../security/p5-Crypt-Random-Seed

PERL5_PACKLIST=		auto/Bytes/Random/Secure/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
