# $NetBSD: Makefile,v 1.11 2011/08/14 14:14:45 obache Exp $

DISTNAME=	Net-Packet-3.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modules to assemble/disassemble network packets
HOMEPAGE=	http://search.cpan.org/dist/Net-Packet/
LICENSE=	artistic

DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Class-Gomor>=1.0:../../devel/p5-Class-Gomor
#DEPENDS+=	p5-IO-Interface-[0-9]*:../../net/p5-IO-Interface
DEPENDS+=	p5-Net-IPv6Addr-[0-9]*:../../net/p5-Net-IPv6Addr
DEPENDS+=	p5-Net-Libdnet>=0.91:../../net/p5-Net-Libdnet
DEPENDS+=	p5-Net-Pcap>=0.14:../../net/p5-Net-Pcap
DEPENDS+=	p5-Net-Write>=1.0:../../net/p5-Net-Write
DEPENDS+=	p5-Socket6-[0-9]*:../../net/p5-Socket6

PKG_INSTALLATION_TYPES=		overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb2

PERL5_PACKLIST=		auto/Net/Packet/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
