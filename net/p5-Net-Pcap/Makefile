# $NetBSD: Makefile,v 1.11 2007/01/03 13:44:03 adrianp Exp $
#

DISTNAME=	Net-Pcap-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Pcap/
COMMENT=	Perl interface to pcap(3) LBL packet capture library

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.5

PERL5_PACKLIST=	auto/Net/Pcap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
