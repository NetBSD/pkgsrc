# $NetBSD: Makefile,v 1.3 2011/04/23 04:12:50 obache Exp $
#

DISTNAME=	groonga-1.2.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://groonga.org/files/groonga/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://groonga.org/
COMMENT=	Fulltext search engine and column store
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

PKGCONFIG_OVERRIDE+=	groonga.pc.in

PKG_SYSCONFSUBDIR=	${PKGBASE}

BUILD_DEFS+=		VARBASE

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CONF_FILES+=		share/examples/${PKGBASE}/groonga.conf \
			${PKG_SYSCONFDIR}/groonga.conf

OWN_DIRS+=		${VARBASE}/log/${PKGBASE}

CHECK_WRKREF_SKIP+=	bin/groonga
CHECK_INTERPRETER_SKIP+=	share/groonga/examples/*
# XXX: should be in separate package.
CHECK_INTERPRETER_SKIP+=	share/groonga/munin/plugins/*

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
