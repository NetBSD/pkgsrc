# $NetBSD: Makefile,v 1.16 2022/06/28 11:35:13 wiz Exp $
#

DISTNAME=	Net-SMTP-TLS-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-SMTP-TLS
COMMENT=	Perl5 SMTP client module supporting TLS and AUTH
LICENSE=	${PERL5_LICENSE} # see README

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Net/SMTP/TLS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
