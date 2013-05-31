# $NetBSD: Makefile,v 1.15 2013/05/31 12:41:39 wiz Exp $
#

DISTNAME=	Net-RawIP-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5nsn
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-RawIP/
COMMENT=	Perl extension to manipulate raw ip packets with interface to libpcap
LICENSE=	gnu-gpl-v2 # OR artistic

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/Net/RawIP/.packlist

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
