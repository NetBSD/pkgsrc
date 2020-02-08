# $NetBSD: Makefile,v 1.28 2020/02/08 17:21:14 fcambus Exp $

DISTNAME=	NetPacket-1.7.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetPacket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modules to assemble/disassemble network packets
HOMEPAGE=	https://metacpan.org/release/NetPacket
LICENSE=	${PERL5_LICENSE} # source doc wins over changelog

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/NetPacket/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
