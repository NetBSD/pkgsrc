# $NetBSD: Makefile,v 1.5 2000/04/06 22:36:56 jlam Exp $

DISTNAME=	libPropList-0.10.0
PKGNAME=	libproplist-0.10.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/

MAINTAINER=	jlam@netbsd.org

GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
