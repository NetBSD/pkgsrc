# $NetBSD: Makefile,v 1.26 2009/08/24 13:50:03 hasso Exp $
#

DISTNAME=		libpreludedb-0.9.15.3
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.com/download/releases/libpreludedb/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Provides an interface to the database used to store IDMEF alerts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		make
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_LANGUAGES=		c c++

.include "options.mk"

pre-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/libltdl.la ${BUILDLINK_DIR}/lib/libltdlc.la

post-install:
	${INSTALL_DATA} ${FILESDIR}/addIndices.sql ${DESTDIR}${PREFIX}/share/libpreludedb/classic

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
