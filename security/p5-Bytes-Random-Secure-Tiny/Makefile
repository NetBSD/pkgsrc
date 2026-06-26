# $NetBSD: Makefile,v 1.3 2026/06/26 17:04:18 wiz Exp $

DISTNAME=	Bytes-Random-Secure-Tiny-1.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bytes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Bytes-Random-Secure-Tiny
COMMENT=	Perl extension to generate cryptographically-secure random bytes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Bytes/Random/Secure/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
