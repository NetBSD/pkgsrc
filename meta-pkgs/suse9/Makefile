# $NetBSD: Makefile,v 1.2 2005/05/10 01:33:50 jschauma Exp $
#

DISTNAME=	suse-9.1
PKGREVISION=	# empty
CATEGORIES=	meta-pkgs emulators
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Provides a SuSE-based Linux binary emulation environment

DEPENDS+=	suse_base>=9.1:../../emulators/suse91_base
DEPENDS+=	suse_compat>=9.1:../../emulators/suse91_compat
DEPENDS+=	suse_x11>=9.1:../../emulators/suse91_x11
DEPENDS+=	suse_libpng>=9.1:../../emulators/suse91_libpng
DEPENDS+=	suse_libjpeg>=9.1:../../emulators/suse91_libjpeg
DEPENDS+=	suse_freetype2>=9.1:../../emulators/suse91_freetype2
DEPENDS+=	suse_openmotif>=9.1:../../emulators/suse91_openmotif
DEPENDS+=	suse_gtk>=9.1:../../emulators/suse91_gtk
DEPENDS+=	suse_locale>=9.1:../../emulators/suse91_locale

# these could possibly be installed too, but probably of less
# general interested, so commented out for now
#DEPENDS+=	suse_gnome2>=9.1:../../emulators/suse91_gnome2
#DEPENDS+=	suse_aspell>=9.1:../../emulators/suse91_aspell

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
