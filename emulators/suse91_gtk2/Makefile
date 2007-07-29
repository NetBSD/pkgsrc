# $NetBSD: Makefile,v 1.18 2007/07/29 05:19:13 jlam Exp $

DISTNAME=	suse_gtk2-${SUSE_VERSION}
PKGREVISION=	7
CATEGORIES=	emulators

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-2.x

EMUL_MODULES.linux=	fontconfig freetype2 jpeg png tiff x11

# Initialize gtk/pango modules.
FILES_SUBST+=		EMULDIR=${EMULDIR:Q}
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
