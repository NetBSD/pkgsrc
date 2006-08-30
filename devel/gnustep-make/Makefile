# $NetBSD: Makefile,v 1.34 2006/08/30 14:53:28 adam Exp $

DISTNAME=	gnustep-make-1.13.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	objc
USE_TOOLS+=	csh

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
CONFIGURE_ARGS+=	--disable-importing-config-file
CONFIGURE_ARGS+=	--with-config-file=${PREFIX}/etc/GNUstep.conf

CONF_FILES+=		${PREFIX}/share/examples/GNUstep/GNUstep.conf \
			${PREFIX}/etc/GNUstep.conf

REPLACE_INTERPRETER+=	csh
REPLACE.csh.old=	/bin/csh
REPLACE.csh.new=	${CSH}
REPLACE_FILES.csh=	ld_lib_path.csh

.include "../../mk/x11.buildlink3.mk"
.include "gnustep.mk"

.if ${MACHINE_ARCH} == "i386"
GNUSTEP_ARCH=	ix86
.else
GNUSTEP_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUBST+=	GNUSTEP_ARCH=${GNUSTEP_ARCH}

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
