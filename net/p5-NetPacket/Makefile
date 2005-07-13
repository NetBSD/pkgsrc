# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:37 jlam Exp $

DISTNAME=	NetPacket-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetPacket/}

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Modules to assemble/disassemble network packets

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/NetPacket/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
