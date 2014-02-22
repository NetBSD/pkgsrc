# $NetBSD: Makefile,v 1.12 2014/02/22 14:10:06 wiedi Exp $
#

DISTNAME=		partysip-2.2.3
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://savannah.gnu.org/download/partysip/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/partysip/partysip.html
COMMENT=		SIP proxy server
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-config-dir=/etc
USE_LIBTOOL=		yes

INSTALLATION_DIRS=	share/examples

LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/partysip.conf ${DESTDIR}${PREFIX}/share/examples

.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
