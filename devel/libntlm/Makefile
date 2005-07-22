# $NetBSD: Makefile,v 1.11 2005/07/22 23:45:22 wiz Exp $
#

DISTNAME=		libntlm-0.3.7
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/libntlm/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://josefsson.org/libntlm/
COMMENT=		Library that implement Microsoft's NTLM authentication

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=    libntlm.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
