# $NetBSD: Makefile,v 1.7 2004/10/01 08:46:26 wiz Exp $
#

DISTNAME=		libntlm-0.3.6
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
