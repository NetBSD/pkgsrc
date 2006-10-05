# $NetBSD: Makefile,v 1.2 2006/10/05 14:55:21 gdt Exp $

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fann.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fann
	(cd ${WRKSRC} && ${INSTALL_DATA} doc/* ${PREFIX}/share/doc/fann)

.include "../../mk/bsd.pkg.mk"
