# $NetBSD: Makefile,v 1.20 2023/07/06 09:41:09 wiz Exp $
#

DISTNAME=	Net-MAC-2.103622
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-MAC
COMMENT=	Perl 5 module for representing and manipulating MAC addresses
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/MAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
