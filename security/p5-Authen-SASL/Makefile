# $NetBSD: Makefile,v 1.37 2023/07/06 09:41:19 wiz Exp $

DISTNAME=	Authen-SASL-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
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
