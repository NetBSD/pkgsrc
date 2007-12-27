# $NetBSD: Makefile,v 1.20 2007/12/27 16:31:23 joerg Exp $
#

DISTNAME=		libpreludedb-0.9.13
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/ \
			http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Provides an interface to the database used to store IDMEF alerts

.include "../../mk/mysql.buildlink3.mk"

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		make perl:run
CONFIGURE_ARGS+=	-enable-mysql
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--with-pgsql=no
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}
PYBINMODULE=		yes
PY_PATCHPLIST=		yes

post-install:
	${INSTALL_DATA} ${FILESDIR}/addIndices.sql ${PREFIX}/share/libpreludedb/classic

.include "../../security/libprelude/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
