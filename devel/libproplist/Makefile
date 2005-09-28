# $NetBSD: Makefile,v 1.19 2005/09/28 20:52:19 rillig Exp $

DISTNAME=		libPropList-0.10.1
PKGNAME=		libproplist-0.10.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/libs/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		GNUstep/OPENSTEP property lists compatibility library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
