# $NetBSD: Makefile,v 1.13 2005/09/30 13:26:24 wiz Exp $
#

DISTNAME=		libntlm-0.3.8
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/libntlm/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://josefsson.org/libntlm/
COMMENT=		Library that implement Microsoft's NTLM authentication

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=    libntlm.pc.in

.include "../../mk/bsd.pkg.mk"
