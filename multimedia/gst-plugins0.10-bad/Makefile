# $NetBSD: Makefile,v 1.15 2011/04/24 15:31:09 obache Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "Makefile.common"

COMMENT+=		bad plugins
PKGREVISION=		1

# builds gsettings module
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.26.0

# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
