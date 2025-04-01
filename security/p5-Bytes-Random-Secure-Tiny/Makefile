# $NetBSD: Makefile,v 1.1 2025/04/01 16:59:51 abs Exp $

DISTNAME=	Bytes-Random-Secure-Tiny-1.011
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bytes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Bytes-Random-Secure-Tiny
COMMENT=	Perl extension to generate cryptographically-secure random bytes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Bytes/Random/Secure/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
