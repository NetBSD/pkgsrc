# $NetBSD: Makefile,v 1.4 2005/08/06 06:19:27 jlam Exp $
#

DISTNAME=	Net-RawIP-0.2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nsn
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~skolychev/Net-RawIP-0.2/RawIP.pm
COMMENT=	Perl extension to manipulate raw ip packets with interface to libpcap

PERL5_PACKLIST=		auto/Net/RawIP/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
