# $NetBSD: Makefile,v 1.1.1.1 2006/06/10 14:24:33 salo Exp $
#

DISTNAME=	suse-10.0
CATEGORIES=	meta-pkgs emulators
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SUSE-based Linux binary emulation environment

# This list should contain all suse100_* packages.
#
DEPENDS+=	suse_base>=10.0:../../emulators/suse100_base
DEPENDS+=	suse_aspell>=10.0:../../emulators/suse100_aspell
DEPENDS+=	suse_compat>=10.0:../../emulators/suse100_compat
DEPENDS+=	suse_expat>=10.0:../../emulators/suse100_expat
DEPENDS+=	suse_fontconfig>=10.0:../../emulators/suse100_fontconfig
DEPENDS+=	suse_freetype2>=10.0:../../emulators/suse100_freetype2
DEPENDS+=	suse_gdk-pixbuf>=10.0:../../emulators/suse100_gdk-pixbuf
DEPENDS+=	suse_glx>=10.0:../../emulators/suse100_glx
DEPENDS+=	suse_gtk2>=10.0:../../emulators/suse100_gtk2
DEPENDS+=	suse_gtk>=10.0:../../emulators/suse100_gtk
DEPENDS+=	suse_libjpeg>=10.0:../../emulators/suse100_libjpeg
DEPENDS+=	suse_libpng>=10.0:../../emulators/suse100_libpng
DEPENDS+=	suse_libtiff>=10.0:../../emulators/suse100_libtiff
DEPENDS+=	suse_locale>=10.0:../../emulators/suse100_locale
DEPENDS+=	suse_locale>=10.0:../../emulators/suse100_locale
DEPENDS+=	suse_openmotif>=10.0:../../emulators/suse100_openmotif
DEPENDS+=	suse_slang>=10.0:../../emulators/suse100_slang
DEPENDS+=	suse_x11>=10.0:../../emulators/suse100_x11

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
