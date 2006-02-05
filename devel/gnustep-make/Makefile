# $NetBSD: Makefile,v 1.26 2006/02/05 23:08:43 joerg Exp $

DISTNAME=	gnustep-make-1.11.2
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}

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
