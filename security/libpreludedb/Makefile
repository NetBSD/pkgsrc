# $NetBSD: Makefile,v 1.34 2013/05/31 12:41:51 wiz Exp $
#

COMMENT=		LibPreludeDB libraries
PKGREVISION=		5

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
