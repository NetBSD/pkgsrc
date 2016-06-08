# $NetBSD: Makefile,v 1.2 2016/06/08 19:24:14 wiz Exp $

DISTNAME=	NetAddr-MAC-0.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NetAddr-MAC/
COMMENT=	Perl5 module handling hardware MAC Addresses (EUI-48 and EUI-64)
LICENSE=	artistic OR gnu-gpl-v2


PERL5_PACKLIST=		auto/NetAddr/MAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
