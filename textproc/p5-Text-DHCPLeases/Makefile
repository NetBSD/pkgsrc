# $NetBSD: Makefile,v 1.2 2009/01/11 16:26:31 he Exp $

DISTNAME=	Text-DHCPLeases-v0.8
PKGNAME=	p5-Text-DHCPLeases-0.8
CATEGORIES=	textproc net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-DHCPLeases/
COMMENT=	Perl 5 module to parse DHCP leases file from ISC dhcpd

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_REQD+=	5.8.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/DHCPLeases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
