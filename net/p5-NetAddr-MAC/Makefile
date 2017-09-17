# $NetBSD: Makefile,v 1.4 2017/09/17 20:58:41 wiz Exp $

DISTNAME=	NetAddr-MAC-0.95
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NetAddr-MAC/
COMMENT=	Perl5 module handling hardware MAC Addresses (EUI-48 and EUI-64)
LICENSE=	artistic OR gnu-gpl-v2

BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap

PERL5_PACKLIST=		auto/NetAddr/MAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
