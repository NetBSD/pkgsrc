# $NetBSD: Makefile,v 1.34 2021/04/21 11:40:31 adam Exp $
#

USE_LANGUAGES=	c c++

.include "Makefile.common"
PKGREVISION=	11

COMMENT+=	Bad plugins

# builds gsettings module
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.26.0

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
