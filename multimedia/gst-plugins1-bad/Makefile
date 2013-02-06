# $NetBSD: Makefile,v 1.3 2013/02/06 23:23:06 jperkin Exp $
#

USE_LANGUAGES=		c c++

.include "Makefile.common"

PKGREVISION=		1
COMMENT+=		bad plugins

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
