# $NetBSD: Makefile,v 1.18 2012/01/03 09:26:22 sbd Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "Makefile.common"

COMMENT+=		bad plugins
PKGREVISION=		2

# builds gsettings module
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.26.0

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
