# $NetBSD: Makefile,v 1.5 2013/04/06 03:45:19 rodent Exp $
#

USE_LANGUAGES=	c c++

.include "Makefile.common"

COMMENT+=	Bad plugins

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
