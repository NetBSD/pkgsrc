# $NetBSD: Makefile,v 1.25 2008/02/12 14:33:12 obache Exp $

.include "Makefile.common"

CATEGORIES=	japanese textproc www

COMMENT=	Full-text search system for communities

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
