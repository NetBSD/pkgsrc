# $NetBSD: Makefile,v 1.26 2009/05/25 09:48:50 obache Exp $

.include "Makefile.common"

CATEGORIES=	japanese textproc www

COMMENT=	Full-text search system for communities
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	hyperestraier.pc.in
TEST_TARGET=		check

BUILDLINK_API_DEPENDS.qdbm+=	qdbm>=1.8.75

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
