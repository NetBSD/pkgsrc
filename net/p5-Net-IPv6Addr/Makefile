# $NetBSD: Makefile,v 1.20 2018/10/20 14:10:02 wen Exp $

DISTNAME=	Net-IPv6Addr-0.96
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~tmonroe/Net-IPv6Addr/
COMMENT=	Check the validity of IPv6 addresses

DEPENDS+=	p5-Math-Base85>=0.2:../../math/p5-Math-Base85
DEPENDS+=	p5-Net-IPv4Addr>=0.10:../../net/p5-Net-IPv4Addr
DEPENDS+=	p5-Math-BigInt>=1.999813:../../math/p5-Math-BigInt

PERL5_PACKLIST=		auto/Net/IPv6Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
