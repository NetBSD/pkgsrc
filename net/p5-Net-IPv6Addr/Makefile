# $NetBSD: Makefile,v 1.25 2021/05/24 19:53:28 wiz Exp $

DISTNAME=	Net-IPv6Addr-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TMONROE/Net-IPv6Addr-0.2
COMMENT=	Check the validity of IPv6 addresses
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-Base85>=0.2:../../math/p5-Math-Base85
DEPENDS+=	p5-Net-IPv4Addr>=0.10:../../net/p5-Net-IPv4Addr
DEPENDS+=	p5-Math-BigInt>=1.999813:../../math/p5-Math-BigInt

PERL5_PACKLIST=		auto/Net/IPv6Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
