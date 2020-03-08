# $NetBSD: Makefile,v 1.13 2020/03/08 16:47:58 wiz Exp $

USE_LANGUAGES=	c c++

PKGREVISION= 2
.include "Makefile.common"

COMMENT+=	Bad plugins

.include "../../devel/glib2/schemas.mk"
# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
# same for OpenSSL
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
