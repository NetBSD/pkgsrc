# $NetBSD: Makefile,v 1.45 2026/07/16 19:04:40 wiz Exp $

DISTNAME=	Authen-SASL-2.2000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EH/EHUELS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Authen-SASL
COMMENT=	Perl module to handle SASL authentication
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Crypt-URandom-[0-9]*:../../security/p5-Crypt-URandom

PERL5_PACKLIST=		auto/Authen/SASL/.packlist

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
