# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:07 grant Exp $

DISTNAME=	NetPacket-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetPacket/}

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Modules to assemble/disassemble network packets

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NetPacket/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
