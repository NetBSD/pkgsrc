# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:27 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "Makefile.common"

COMMENT+=		bad plugins

# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
