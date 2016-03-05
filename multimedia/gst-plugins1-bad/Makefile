# $NetBSD: Makefile,v 1.10 2016/03/05 11:29:00 jperkin Exp $

USE_LANGUAGES=	c c++

PKGREVISION= 1
.include "Makefile.common"

COMMENT+=	Bad plugins

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
