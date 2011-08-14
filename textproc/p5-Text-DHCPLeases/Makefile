# $NetBSD: Makefile,v 1.5 2011/08/14 15:14:11 obache Exp $

DISTNAME=	Text-DHCPLeases-0.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-DHCPLeases/
COMMENT=	Perl 5 module to parse DHCP leases file from ISC dhcpd
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_REQD+=	5.8.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/DHCPLeases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
