# $NetBSD: Makefile,v 1.3 1999/04/22 04:08:50 jlam Exp $

DISTNAME=	libPropList-0.8.3
PKGNAME=	libproplist-0.8.3
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
