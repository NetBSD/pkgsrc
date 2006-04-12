# $NetBSD: Makefile,v 1.8 2006/04/12 19:40:51 joerg Exp $
#
DISTNAME=		libprelude-0.9.7
PKGREVISION=		1
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
USE_TOOLS+=		make bison gawk
PKG_SYSCONFSUBDIR= 	prelude
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME?=		${VARBASE:Q}/spool/prelude
PKG_USERS=	${PRELUDE_USER}:${PRELUDE_GROUP}::Prelude\ IDS:${PRELUDE_HOME}:${NOLOGIN}
PKG_GROUPS=	${PRELUDE_GROUP}

CONF_FILES+=	${PREFIX}/share/examples/libprelude/client.conf ${PKG_SYSCONFDIR}/client.conf
CONF_FILES+=	${PREFIX}/share/examples/libprelude/global.conf ${PKG_SYSCONFDIR}/global.conf
CONF_FILES+=	${PREFIX}/share/examples/libprelude/idmef-client.conf ${PKG_SYSCONFDIR}/idmef-client.conf
CONF_FILES+=	${PREFIX}/share/examples/libprelude/tls.conf ${PKG_SYSCONFDIR}/tls.conf

post-install:
	${CHOWN} -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
