# $NetBSD: Makefile,v 1.11 2001/10/02 08:49:51 wiz Exp $

DISTNAME=		libPropList-0.10.1
PKGNAME=		libproplist-0.10.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/libs/

MAINTAINER=		jlam@netbsd.org
COMMENT=		GNUstep/OPENSTEP property lists compatibility library

GNU_CONFIGURE=		# defined
USE_BUILDLINK_ONLY=	# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
