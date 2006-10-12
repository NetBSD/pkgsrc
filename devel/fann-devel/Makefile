# $NetBSD: Makefile,v 1.1.1.1 2006/10/12 18:30:22 gdt Exp $

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	fann.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fann
	(cd ${WRKSRC} && ${INSTALL_DATA} doc/* ${PREFIX}/share/doc/fann)

.include "../../mk/bsd.pkg.mk"
