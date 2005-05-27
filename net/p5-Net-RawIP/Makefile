# $NetBSD: Makefile,v 1.1.1.1 2005/05/27 15:12:53 bouyer Exp $
#

DISTNAME=	Net-RawIP-0.2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nsn
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~skolychev/Net-RawIP-0.2/RawIP.pm
COMMENT=	Perl extension to manipulate raw ip packets with interface to libpcap

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/RawIP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
