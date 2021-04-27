# $NetBSD: Makefile,v 1.39 2021/04/27 12:08:24 wiz Exp $

DISTNAME=	Digest-HMAC-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-HMAC
COMMENT=	Perl5 module for HMAC
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Digest/HMAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
