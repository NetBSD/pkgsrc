# $NetBSD: Makefile,v 1.14 2018/08/22 09:46:59 wiz Exp $

DISTNAME=	Text-DHCPLeases-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-DHCPLeases/
COMMENT=	Perl 5 module to parse DHCP leases file from ISC dhcpd
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/DHCPLeases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
