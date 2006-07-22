# $NetBSD: Makefile,v 1.30 2006/07/22 05:10:54 rillig Exp $

DISTNAME=	gnustep-make-1.12.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	objc

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}

CONF_FILES+=		${PREFIX}/share/examples/GNUstep/GNUstep.conf \
			${PREFIX}/etc/GNUstep.conf

.include "../../mk/x11.buildlink3.mk"
.include "gnustep.mk"

SUBST_CLASSES+=		target
SUBST_STAGE.target=	post-patch
SUBST_FILES.target=	target.make
SUBST_SED.target+=	-e 's|/usr/pkg|${LOCALBASE}|g'

post-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/GNUstep/Local/Applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Bundles
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Frameworks
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Headers
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Libraries
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Network

.include "../../mk/bsd.pkg.mk"
