# $NetBSD: Makefile,v 1.5 2020/04/18 13:24:25 mef Exp $

DISTNAME=	Net-Frame-Layer-ICMPv6-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Internet Control Message Protocol v6 layer object
HOMEPAGE=	https://metacpan.org/release/Net-Frame-Layer-ICMPv6
LICENSE=	artistic

DEPENDS+=	p5-Net-Frame-[0-9]*:../../net/p5-Net-Frame
DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector

PERL5_PACKLIST=		auto/Net/Frame/Layer/ICMPv6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
