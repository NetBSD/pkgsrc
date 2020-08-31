# $NetBSD: Makefile,v 1.17 2020/08/31 18:12:00 wiz Exp $

DISTNAME=	Text-DHCPLeases-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-DHCPLeases
COMMENT=	Perl 5 module to parse DHCP leases file from ISC dhcpd
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/DHCPLeases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
