# $NetBSD: Makefile,v 1.4 2013/03/15 18:34:46 drochner Exp $
#

USE_LANGUAGES=		c c++

.include "Makefile.common"

COMMENT+=		bad plugins

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
