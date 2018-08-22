# $NetBSD: Makefile,v 1.19 2018/08/22 09:46:00 wiz Exp $

DISTNAME=	Net-IPv6Addr-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~tmonroe/Net-IPv6Addr/
COMMENT=	Check the validity of IPv6 addresses

DEPENDS+=	p5-Math-Base85-[0-9]*:../../math/p5-Math-Base85
DEPENDS+=	p5-Net-IPv4Addr-[0-9]*:../../net/p5-Net-IPv4Addr

PERL5_PACKLIST=		auto/Net/IPv6Addr/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
