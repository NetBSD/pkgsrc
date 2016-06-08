# $NetBSD: Makefile,v 1.23 2016/06/08 19:24:11 wiz Exp $
#

DISTNAME=	Net-IP-1.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-IP/
COMMENT=	Perl extension for manipulating IPv4/IPv6 addresses
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
