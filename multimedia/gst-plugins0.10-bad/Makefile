# $NetBSD: Makefile,v 1.23 2012/09/15 10:05:47 obache Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "Makefile.common"
PKGREVISION=		3

COMMENT+=		bad plugins

# builds gsettings module
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.26.0

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
