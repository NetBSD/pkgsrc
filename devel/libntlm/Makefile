# $NetBSD: Makefile,v 1.6 2004/09/20 23:24:58 wiz Exp $
#

DISTNAME=		libntlm-0.3.3
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/libntlm/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://josefsson.org/libntlm/
COMMENT=		Library that implement Microsoft's NTLM authentication

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=    libntlm.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
