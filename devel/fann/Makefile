# $NetBSD: Makefile,v 1.4 2012/10/31 11:16:57 asau Exp $

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fann.pc.in

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/doc/fann
	(cd ${WRKSRC} && ${INSTALL_DATA} doc/* ${DESTDIR}/${PREFIX}/share/doc/fann)

.include "../../mk/bsd.pkg.mk"
