# $NetBSD: Makefile,v 1.4 2005/08/11 18:19:14 drochner Exp $
#

DISTNAME=		partysip-2.2.3
CATEGORIES=		net
MASTER_SITES=		http://savannah.gnu.org/download/partysip/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/partysip/partysip.html
COMMENT=		SIP proxy server

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-config-dir=/etc
USE_LIBTOOL=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/partysip.conf ${PREFIX}/share/examples

.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
