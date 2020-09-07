# $NetBSD: Makefile,v 1.16 2020/09/07 11:45:46 wiz Exp $

DISTNAME=	Net-validMX-2.5.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/KMCGRAIL/Net-validMX-2.2.0
COMMENT=	Use DNS and/or regular expressions to verify a email address
LICENSE=	artistic

DEPENDS+=	p5-Net-DNS>=0.53:../../net/p5-Net-DNS

PERL5_PACKLIST=	auto/Net/validMX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
