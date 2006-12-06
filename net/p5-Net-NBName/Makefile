# $NetBSD: Makefile,v 1.1.1.1 2006/12/06 23:12:03 bouyer Exp $
#

DISTNAME=	Net-NBName-0.26
PKGNAME=	p5-${DISTNAME}
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
