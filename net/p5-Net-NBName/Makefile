# $NetBSD: Makefile,v 1.8 2013/02/06 19:30:59 jperkin Exp $
#

DISTNAME=	Net-NBName-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5nbn
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jmacfarla/Net-NBName-0.26/
COMMENT=	Perl extension to perform simple NetBIOS Name Service Requests

PERL5_PACKLIST=		auto/Net/NBName/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
