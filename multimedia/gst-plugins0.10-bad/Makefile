# $NetBSD: Makefile,v 1.38 2022/04/18 19:09:59 adam Exp $
#

USE_LANGUAGES=	c c++

.include "Makefile.common"
PKGREVISION=	13

COMMENT+=	Bad plugins

# really adhoc fix
# intention is that the file gst-libs/gst/interfaces/photography-enumtypes.c
# should have the line
#    #include "photography.h"
# instead of
#   \#include "photography.h"
# To do that, modify generating Makefile to insert sed command
# It may be by some problems on glib-mkenums (in glib2-tools-2.68.3)

SED_STRING=	',$$^ > $$@,$$^ | sed -e "s/\\\\\\\#include/\#include/" > $$@,'

SUBST_CLASSES+=			backslash
SUBST_FILES.backslash=		gst-libs/gst/interfaces/Makefile
SUBST_MESSAGE.backslash=	Remove unnecessary bachslash
SUBST_SED.backslash=		-e '/enumtypes.c:/,/ a hack rule to make sure/'s${SED_STRING}
SUBST_STAGE.backslash=		post-configure


# builds gsettings module
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.26.0

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
