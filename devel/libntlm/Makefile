# $NetBSD: Makefile,v 1.10 2005/07/21 16:29:48 wiz Exp $
#

DISTNAME=		libntlm-0.3.6
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/libntlm/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://josefsson.org/libntlm/
COMMENT=		Library that implement Microsoft's NTLM authentication

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=    libntlm.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
