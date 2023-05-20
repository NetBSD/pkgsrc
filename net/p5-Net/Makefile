# $NetBSD: Makefile,v 1.76 2023/05/20 07:05:45 wiz Exp $

DISTNAME=	libnet-3.15
PKGNAME=	p5-${DISTNAME:S/libnet/Net/}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/libnet
COMMENT=	Perl5 modules to access and use network protocols
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
