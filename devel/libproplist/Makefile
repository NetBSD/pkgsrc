# $NetBSD: Makefile,v 1.9 2001/02/16 14:38:37 wiz Exp $

DISTNAME=		libPropList-0.10.1
PKGNAME=		libproplist-0.10.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/

MAINTAINER=		jlam@netbsd.org
COMMENT=		GNUstep/OPENSTEP property lists compatibility library

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
