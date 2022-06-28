# $NetBSD: Makefile,v 1.8 2022/06/28 11:35:10 wiz Exp $

DISTNAME=	Net-Frame-Layer-ICMPv6-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
