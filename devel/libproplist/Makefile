# $NetBSD: Makefile,v 1.16 2004/04/24 22:46:09 jlam Exp $

DISTNAME=		libPropList-0.10.1
PKGNAME=		libproplist-0.10.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/libs/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		GNUstep/OPENSTEP property lists compatibility library

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		yes
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
