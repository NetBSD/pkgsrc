# $NetBSD: Makefile,v 1.82 2026/11/22 08:33:00 wiz Exp $

DISTNAME=	libnet-3.17
PKGNAME=	p5-${DISTNAME:S/libnet/Net/}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/libnet
COMMENT=	Perl5 modules to access and use network protocols
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
