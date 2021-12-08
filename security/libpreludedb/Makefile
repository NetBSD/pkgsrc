# $NetBSD: Makefile,v 1.51 2021/12/08 16:02:34 adam Exp $
#

COMMENT=		LibPreludeDB libraries
PKGREVISION=		22

.include "../../security/libpreludedb/Makefile.common"

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

post-install:
	${INSTALL_DATA} ${FILESDIR}/addIndices.sql ${DESTDIR}${PREFIX}/share/libpreludedb/classic

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
