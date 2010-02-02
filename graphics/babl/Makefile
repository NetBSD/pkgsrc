# $NetBSD: Makefile,v 1.6 2010/02/02 14:09:58 adam Exp $

DISTNAME=	babl-${BABL_VERSION}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/babl/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
###
### NOTE: to build documentation--which requires additional dependencies--
###	  define BUILD_DOCS in MAKE_ENV.
###
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	babl.pc.in

.include "Makefile.version"

# Work around broken makefile, please see here:
# http://bugzilla.gnome.org/show_bug.cgi?id=569085
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
SUBST_CLASSES+=		plugin
SUBST_STAGE.plugin=	post-configure
SUBST_FILES.plugin=	extensions/Makefile
SUBST_SED.plugin=	-e "s/SHREXT = .dylib/SHREXT = .so/"
SUBST_SED.plugin+=	-e "s/DYNAMICLIB = -dynamiclib/DYNAMICLIB = -bundle/"
SUBST_SED.plugin+=	-e "s/BABL_API_VERSION...SHREXT./BABL_API_VERSION).dylib/"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
