# $NetBSD: Makefile,v 1.17 2019/08/11 13:22:21 wiz Exp $
#

DISTNAME=	Net-NBName-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JMACFARLA/Net-NBName-0.26
COMMENT=	Perl extension to perform simple NetBIOS Name Service Requests

PERL5_PACKLIST=		auto/Net/NBName/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
