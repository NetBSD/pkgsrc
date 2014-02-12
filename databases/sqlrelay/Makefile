# $NetBSD: Makefile,v 1.33 2014/02/12 23:17:45 tron Exp $

DISTNAME=		sqlrelay-0.43
PKGREVISION=		10
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlrelay/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sqlrelay.sourceforge.net/
COMMENT=		Enables pooling and sharing of database connections
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-db2
CONFIGURE_ARGS+=	--disable-erlang
CONFIGURE_ARGS+=	--disable-firebird
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-mdbtools
CONFIGURE_ARGS+=	--disable-oracle
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-sybase
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-zope
CONFIGURE_ARGS+=	--with-rudiments-prefix=${BUILDLINK_PREFIX.rudiments}
MAKE_ENV+=		EXAMPLESDIR=${EGDIR:Q}

PKG_SYSCONFSUBDIR=	sqlrelay
EGDIR=			${PREFIX}/share/examples/sqlrelay

CONF_FILES+=		${EGDIR}/sqlrelay.conf.example \
			${PKG_SYSCONFDIR}/sqlrelay.conf
CONF_FILES+=		${EGDIR}/sqlrelay.dtd \
			${PKG_SYSCONFDIR}/sqlrelay.dtd
CONF_FILES+=		${EGDIR}/sqlrelay \
			${PKG_SYSCONFDIR}/sqlrelay

INSTALLATION_DIRS=	${PREFIX}/share/examples/rc.d

SQLR_DATA?=		${VARBASE}/sqlrelay
OWN_DIRS+=		${SQLR_DATA}
OWN_DIRS+=		${SQLR_DATA}/tmp
OWN_DIRS+=		${SQLR_DATA}/tmp/ipc
OWN_DIRS+=		${SQLR_DATA}/tmp/pids
OWN_DIRS+=		${SQLR_DATA}/tmp/sockets

RCD_SCRIPTS+=		sqlrelay
RCD_SCRIPT_SRC.sqlrelay=	${WRKSRC}/init/netbsd/rc.d/sqlrelay

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/init/netbsd/sqlrelay ${DESTDIR}${EGDIR}/sqlrelay

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
