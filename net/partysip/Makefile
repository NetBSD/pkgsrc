# $NetBSD: Makefile,v 1.1.1.1 2005/04/01 19:55:02 drochner Exp $
#

DISTNAME=		partysip-2.2.1
CATEGORIES=		net
MASTER_SITES=		http://savannah.gnu.org/download/partysip/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/partysip/partysip.html
COMMENT=		SIP proxy server

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-config-dir=/etc
USE_LIBTOOL=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/partysip.conf ${PREFIX}/share/examples

.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
