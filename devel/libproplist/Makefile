# $NetBSD: Makefile,v 1.4 1999/10/05 20:18:32 tron Exp $

DISTNAME=	libPropList-0.9.1
PKGNAME=	libproplist-0.9.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/libs/ \
		ftp://ftp.gnome.org/pub/libPropList/

MAINTAINER=	jlam@netbsd.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libPropList
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libPropList

.include "../../mk/bsd.pkg.mk"
