# $NetBSD: Makefile,v 1.7 2000/06/01 11:23:22 rh Exp $

DISTNAME=	libPropList-0.10.1
PKGNAME=	libproplist-0.10.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.windowmaker.org/pub/beta/srcs/

MAINTAINER=	jlam@netbsd.org

GNU_CONFIGURE=	# defined
USE_PKGLIBTOOL=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
