# $NetBSD: Makefile,v 1.18 2014/05/29 23:37:10 wiz Exp $

DISTNAME=	NetPacket-1.3.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetPacket/}

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Modules to assemble/disassemble network packets
HOMEPAGE=	http://search.cpan.org/dist/NetPacket/
LICENSE=	${PERL5_LICENSE} # source doc wins over changelog

USE_LANGUAGES=	c

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/NetPacket/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
