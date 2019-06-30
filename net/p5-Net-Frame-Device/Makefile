# $NetBSD: Makefile,v 1.4 2019/06/30 20:16:28 nia Exp $

DISTNAME=	Net-Frame-Device-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Get network device information and gateway
HOMEPAGE=	https://metacpan.org/release/Net-Frame-Device
LICENSE=	artistic

DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Net-Libdnet-[0-9]*:../../net/p5-Net-Libdnet
DEPENDS+=	p5-Net-Libdnet6-[0-9]*:../../net/p5-Net-Libdnet6
DEPENDS+=	p5-Net-IPv4Addr-[0-9]*:../../net/p5-Net-IPv4Addr
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr
DEPENDS+=	p5-Net-Pcap>=0.12:../../net/p5-Net-Pcap
DEPENDS+=	p5-Net-Write>=1.0:../../net/p5-Net-Write
DEPENDS+=	p5-Net-Frame-[0-9]*:../../net/p5-Net-Frame
DEPENDS+=	p5-Net-Frame-Dump>=1.08:../../net/p5-Net-Frame-Dump
DEPENDS+=	p5-Net-Frame-Layer-IPv6-[0-9]*:../../net/p5-Net-Frame-Layer-IPv6
DEPENDS+=	p5-Net-Frame-Layer-ICMPv6-[0-9]*:../../net/p5-Net-Frame-Layer-ICMPv6
DEPENDS+=	p5-Net-Frame-Simple-[0-9]*:../../net/p5-Net-Frame-Simple

PERL5_PACKLIST=		auto/Net/Frame/Device/.packlist

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb2
.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
