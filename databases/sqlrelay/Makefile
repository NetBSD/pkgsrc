# $NetBSD: Makefile,v 1.13 2006/04/25 13:51:24 joerg Exp $

DISTNAME=		sqlrelay-0.37
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlrelay/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://sqlrelay.sourceforge.net/
COMMENT=		Enables pooling and sharing of database connections

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-oracle
CONFIGURE_ARGS+=	--disable-sybase
CONFIGURE_ARGS+=	--disable-db2
CONFIGURE_ARGS+=	--disable-interbase
CONFIGURE_ARGS+=	--disable-mdbtools
CONFIGURE_ARGS+=	--disable-msql
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-zope
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-gtk
MAKE_ENV+=		EXAMPLESDIR=${EGDIR:Q}

PKG_SYSCONFSUBDIR=	sqlrelay
EGDIR=			${PREFIX}/share/examples/sqlrelay

CONF_FILES+=		${EGDIR}/sqlrelay.conf.example \
			${PKG_SYSCONFDIR}/sqlrelay.conf
CONF_FILES+=		${EGDIR}/sqlrelay.dtd \
			${PKG_SYSCONFDIR}/sqlrelay.dtd

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/init/netbsd/rc.d/sqlrelay ${PREFIX}/share/examples/rc.d/sqlrelay

RCD_SCRIPTS+=		sqlrelay

.include "options.mk"

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
