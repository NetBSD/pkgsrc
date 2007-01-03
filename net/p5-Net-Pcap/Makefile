# $NetBSD: Makefile,v 1.12 2007/01/03 14:29:11 adrianp Exp $
#

DISTNAME=	Net-Pcap-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Pcap/
COMMENT=	Perl interface to pcap(3) LBL packet capture library

DEPENDS+=	p5-IO-Interface-[0-9]*:../../net/p5-IO-Interface

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.5

PERL5_PACKLIST=	auto/Net/Pcap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
