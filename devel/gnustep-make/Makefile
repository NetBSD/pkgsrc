# $NetBSD: Makefile,v 1.39 2007/11/25 17:18:22 wiz Exp $

DISTNAME=	gnustep-make-2.0.2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

#LICENSE=		gnu-gplv3

USE_LANGUAGES=		objc
USE_TOOLS+=		csh
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
CONFIGURE_ARGS+=	--disable-importing-config-file
CONFIGURE_ARGS+=	--with-config-file=${PREFIX}/etc/GNUstep.conf
MAKE_FILE=		GNUmakefile

CONF_FILES+=		${PREFIX}/share/examples/GNUstep/GNUstep.conf \
			${PKG_SYSCONFDIR}/GNUstep.conf

REPLACE_INTERPRETER+=	csh
REPLACE.csh.old=	/bin/csh
REPLACE.csh.new=	${CSH}
REPLACE_FILES.csh=	ld_lib_path.csh

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

INSTALLATION_DIRS+=	share/GNUstep/Local/Applications
INSTALLATION_DIRS+=	share/GNUstep/Local/Library
INSTALLATION_DIRS+=	share/GNUstep/Local/Library/Bundles
INSTALLATION_DIRS+=	share/GNUstep/Local/Library/Frameworks
INSTALLATION_DIRS+=	share/GNUstep/Local/Library/Headers
INSTALLATION_DIRS+=	share/GNUstep/Local/Library/Libraries
INSTALLATION_DIRS+=	share/GNUstep/Network
INSTALLATION_DIRS+=	share/GNUstep/System/Applications
INSTALLATION_DIRS+=	share/GNUstep/System/Library/ApplicationSupport
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Bundles
INSTALLATION_DIRS+=	share/GNUstep/System/Library/ColorPickers
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Colors
INSTALLATION_DIRS+=	share/GNUstep/System/Library/DocTemplates
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Documentation/Developer
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Documentation/User
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Documentation/info
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Documentation/man
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Fonts
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Frameworks
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Headers
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Images
INSTALLATION_DIRS+=	share/GNUstep/System/Library/KeyBindings
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Libraries/Java
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Libraries/Resources
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Makefiles/${GNUSTEP_ARCH}
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Makefiles/Additional
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Makefiles/Auxiliary
INSTALLATION_DIRS+=	share/GNUstep/System/Library/PostScript
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Services
INSTALLATION_DIRS+=	share/GNUstep/System/Library/Sounds
INSTALLATION_DIRS+=	share/GNUstep/System/Tools/Java
INSTALLATION_DIRS+=	share/GNUstep/System/Tools/Resources

.include "../../mk/bsd.pkg.mk"
