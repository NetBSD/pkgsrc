# $NetBSD: Makefile,v 1.5 2006/06/26 20:37:26 salo Exp $
#

DISTNAME=	suse-9.1
PKGREVISION=	2
CATEGORIES=	meta-pkgs emulators
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Provides a SuSE-based Linux binary emulation environment

# This list should contain all suse91_* packages.
#
DEPENDS+=	suse_base>=9.1:../../emulators/suse91_base/
DEPENDS+=	suse_aspell>=9.1:../../emulators/suse91_aspell
DEPENDS+=	suse_compat>=9.1:../../emulators/suse91_compat
DEPENDS+=	suse_expat>=9.1:../../emulators/suse91_expat
DEPENDS+=	suse_fontconfig>=9.1:../../emulators/suse91_fontconfig
DEPENDS+=	suse_freetype2>=9.1:../../emulators/suse91_freetype2
DEPENDS+=	suse_gdk-pixbuf>=9.1:../../emulators/suse91_gdk-pixbuf
DEPENDS+=	suse_glx>=9.1:../../emulators/suse91_glx
DEPENDS+=	suse_gtk>=9.1:../../emulators/suse91_gtk
DEPENDS+=	suse_gtk2>=9.1:../../emulators/suse91_gtk2
DEPENDS+=	suse_libjpeg>=9.1:../../emulators/suse91_libjpeg
DEPENDS+=	suse_libpng>=9.1:../../emulators/suse91_libpng
DEPENDS+=	suse_libtiff>=9.1:../../emulators/suse91_libtiff
DEPENDS+=	suse_locale>=9.1:../../emulators/suse91_locale
DEPENDS+=	suse_openmotif>=9.1:../../emulators/suse91_openmotif
DEPENDS+=	suse_slang>=9.1:../../emulators/suse91_slang
DEPENDS+=	suse_vmware>=9.1:../../emulators/suse91_vmware
DEPENDS+=	suse_x11>=9.1:../../emulators/suse91_x11

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
