# $NetBSD: Makefile,v 1.12 2022/06/28 11:35:15 wiz Exp $

DISTNAME=	NetAddr-MAC-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetAddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/NetAddr-MAC
COMMENT=	Perl5 module handling hardware MAC Addresses (EUI-48 and EUI-64)
LICENSE=	artistic OR gnu-gpl-v2

BUILD_DEPENDS+=	p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap

PERL5_PACKLIST=		auto/NetAddr/MAC/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
