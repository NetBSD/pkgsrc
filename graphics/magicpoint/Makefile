# $NetBSD: Makefile,v 1.7 1999/06/16 16:21:26 itojun Exp $

DISTNAME=		magicpoint-1.04a
# question is for localized (i.e. Japanese) version
PKGNAME?=		magicpoint-1.04a
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.Mew.org/mgp/

DEPENDS=		freetype-1.1:${.CURDIR}/../../print/freetype

CONFLICTS=		mgp-*

GNU_CONFIGURE=		yes
USE_IMAKE=		yes
CONFIGURE_ARGS+=	--disable-vflib

post-configure:
	(cd ${WRKSRC}/contrib/xmindpath; ./configure --prefix=${PREFIX})

post-build:
	(cd ${WRKSRC}/contrib/xmindpath; make)

post-install:
	(cd ${WRKSRC}/contrib/xmindpath; make install)
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/README* ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/*.gif ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/*.eps ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/*.mgp ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/mgprc-sample ${PREFIX}/share/examples/mgp

.include "../../mk/bsd.pkg.mk"
