# $NetBSD: Makefile,v 1.41 2022/06/28 11:35:46 wiz Exp $

DISTNAME=	Digest-HMAC-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
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
