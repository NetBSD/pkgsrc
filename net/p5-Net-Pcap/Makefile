# $NetBSD: Makefile,v 1.5 2005/07/02 12:22:09 adrianp Exp $
#

DISTNAME=	Net-Pcap-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/KCARNUT/Net-Pcap-0.04/Pcap.pm
COMMENT=	Perl interface to pcap(3) LBL packet capture library

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8.1

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/Pcap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
