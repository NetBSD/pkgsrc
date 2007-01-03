# $NetBSD: Makefile,v 1.4 2007/01/03 14:24:35 adrianp Exp $

DISTNAME=	Net-Packet-3.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Modules to assemble/disassemble network packets

DEPENDS+=	p5-Net-Pcap>=0.14:../../net/p5-Net-Pcap
DEPENDS+=	p5-IO-Interface-[0-9]*:../../net/p5-IO-Interface
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr
DEPENDS+=	p5-Class-Gomor-[0-9]*:../../devel/p5-Class-Gomor
DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Net-Write-[0-9]*:../../net/p5-Net-Write
DEPENDS+=	p5-Net-Libdnet-[0-9]*:../../net/p5-Net-Libdnet

PKG_INSTALLATION_TYPES=		overwrite pkgviews
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb2

PERL5_PACKLIST=		auto/Net/Packet/.packlist

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
PKG_SKIP_REASON+=	"Big endian architectures not supported yet"
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
