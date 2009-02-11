# $NetBSD: Makefile,v 1.3 2009/02/11 00:33:54 gdt Exp $

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fann.pc.in

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/doc/fann
	(cd ${WRKSRC} && ${INSTALL_DATA} doc/* ${DESTDIR}/${PREFIX}/share/doc/fann)

.include "../../mk/bsd.pkg.mk"
