# $NetBSD: Makefile,v 1.10 2016/07/26 06:07:12 wen Exp $

DISTNAME=	Net-Frame-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The base framework for frame crafting
HOMEPAGE=	http://search.cpan.org/dist/Net-Frame/
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr
DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector
SUPERSEDES+=	p5-Net-Packet-[0-9]*

PERL5_PACKLIST=		auto/Net/Frame/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
