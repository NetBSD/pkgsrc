# $NetBSD: Makefile,v 1.22 2019/08/11 13:22:20 wiz Exp $

DISTNAME=	Net-IPv6Addr-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TMONROE/Net-IPv6Addr-0.2
COMMENT=	Check the validity of IPv6 addresses

DEPENDS+=	p5-Math-Base85>=0.2:../../math/p5-Math-Base85
DEPENDS+=	p5-Net-IPv4Addr>=0.10:../../net/p5-Net-IPv4Addr
DEPENDS+=	p5-Math-BigInt>=1.999813:../../math/p5-Math-BigInt

PERL5_PACKLIST=		auto/Net/IPv6Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
