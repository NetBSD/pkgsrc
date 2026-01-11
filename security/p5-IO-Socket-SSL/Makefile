# $NetBSD: Makefile,v 1.152 2026/01/11 04:49:47 wiz Exp $

DISTNAME=	IO-Socket-SSL-2.098
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../..//authors/id/S/SU/SULLR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Socket-SSL
COMMENT=	Perl5 SSL socket interface class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-Net-LibIDN-[0-9]*:../../net/p5-Net-LibIDN
DEPENDS+=	p5-Net-SSLeay>=1.86:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Mozilla-CA-[0-9]*:../../security/p5-Mozilla-CA

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Socket/SSL/.packlist

# as of 2.090, needs network access for t/external/ocsp.t
ALLOW_NETWORK_ACCESS=	yes

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
