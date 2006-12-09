# $NetBSD: Makefile,v 1.15 2006/12/09 13:57:29 obache Exp $
#

DISTNAME=		libntlm-0.3.12
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/libntlm/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://josefsson.org/libntlm/
COMMENT=		Library that implement Microsoft's NTLM authentication

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	libntlm.pc.in

.include "../../mk/bsd.pkg.mk"
