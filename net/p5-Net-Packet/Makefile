# $NetBSD: Makefile,v 1.1.1.1 2005/08/13 08:11:17 adrianp Exp $

DISTNAME=	Net-Packet-2.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Modules to assemble/disassemble network packets

DEPENDS+=	p5-Net-Pcap>0.04:../../net/p5-Net-Pcap
DEPENDS+=	p5-IO-Interface-[0-9]*:../../net/p5-IO-Interface
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr
DEPENDS+=	p5-Class-Gomor-Hash-[0-9]*:../../devel/p5-Class-Gomor-Hash

PKG_INSTALLATION_TYPES=		overwrite pkgviews
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.9.3nb2

PERL5_PACKLIST=		auto/Net/Packet/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
