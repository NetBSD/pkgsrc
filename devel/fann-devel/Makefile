# $NetBSD: Makefile,v 1.2 2009/02/11 00:39:10 gdt Exp $

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	fann.pc.in

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/doc/fann
	(cd ${WRKSRC} && ${INSTALL_DATA} doc/* ${DESTDIR}/${PREFIX}/share/doc/fann)

.include "../../mk/bsd.pkg.mk"
