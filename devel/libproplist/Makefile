# $NetBSD: Makefile,v 1.6 2000/04/07 17:44:42 tron Exp $

DISTNAME=	libPropList-0.10.1
PKGNAME=	libproplist-0.10.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/

MAINTAINER=	jlam@netbsd.org

GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
