# $NetBSD: Makefile,v 1.2 2004/02/10 00:20:29 jlam Exp $
#

DISTNAME=		libntlm-0.3.2
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/libntlm/releases/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://josefsson.org/libntlm/
COMMENT=		Library that implement Microsoft's NTLM authentication

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/libntlm.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
