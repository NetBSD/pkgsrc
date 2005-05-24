# $NetBSD: Makefile,v 1.19 2005/05/24 17:20:00 rillig Exp $

DISTNAME=	gnustep-make-1.10.0
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11=	yes
CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL_SCRIPT}"

.include "gnustep.mk"

post-patch:
	${CP} ${WRKSRC}/target.make ${WRKSRC}/target.make.bak
	${SED}  -e 's;/usr/pkg;${LOCALBASE};g' \
		-e 's;@object_fmt@;${LOWER_OPSYS}-${OBJECT_FMT};g' \
		${WRKSRC}/target.make.bak > ${WRKSRC}/target.make

post-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/GNUstep/Local/Applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Bundles
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Frameworks
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Headers
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Libraries
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Network

.include "../../mk/bsd.pkg.mk"
