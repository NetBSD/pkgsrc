# $NetBSD: Makefile,v 1.40 2025/04/27 05:04:31 wiz Exp $

DISTNAME=	Authen-SASL-2.1800
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Authen-SASL
COMMENT=	Perl module to handle SASL authentication
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC

PERL5_PACKLIST=		auto/Authen/SASL/.packlist

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
