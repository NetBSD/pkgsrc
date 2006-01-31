# $NetBSD: Makefile,v 1.2 2006/01/31 10:44:45 shannonjr Exp $
#
DISTNAME=		libprelude-0.9.4
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Provides the framework for using the Prelude system

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PRELUDE_USER?=          _prelude
PRELUDE_GROUP?=         _prelude

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_TOOLS+=		bison gawk
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME?=		${VARBASE:Q}/spool/prelude
PKG_USERS=	${PRELUDE_USER}:${PRELUDE_GROUP}::Prelude\ IDS:${PRELUDE_HOME}:${NOLOGIN}
PKG_GROUPS=	${PRELUDE_GROUP}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libprelude/
	${INSTALL_DATA} ${WRKSRC}/client.conf \
		${PREFIX}/share/examples/libprelude/client.conf-dist
	${INSTALL_DATA} ${WRKSRC}/global.conf \
		${PREFIX}/share/examples/libprelude/global.conf-dist
	${INSTALL_DATA} ${WRKSRC}/idmef-client.conf \
		${PREFIX}/share/examples/libprelude/idmef-client.conf-dist
	${INSTALL_DATA} ${WRKSRC}/tls.conf \
		${PREFIX}/share/examples/libprelude/tls.conf-dist
	${CHOWN} -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
