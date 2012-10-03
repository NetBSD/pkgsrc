# $NetBSD: Makefile,v 1.9 2012/10/03 11:43:32 asau Exp $

# This section contains variables that might be overridden.
PKGNAME?=	${PKGNAME_BASE}
COMMENT?=	vi clone with regex-search, hex-edit, HTML/LaTeX preview

# Normal package Makefile contents follow.
DISTNAME=	elvis-2.2_0
PKGNAME_BASE=	${DISTNAME:S/_/./}
PKGREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/

CONFLICTS+=	elvis-[0-9]*
CONFLICTS+=	elvis-x11-[0-9]*

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://elvis.vi-editor.org/
LICENSE=	artistic

.include "options.mk"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--verbose
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--docdir=${PREFIX:Q}/share/doc/elvis
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR?=	elvis
CONF_FILES=		${PREFIX}/share/elvis/elvis.rc \
			${PKG_SYSCONFDIR}/elvis.rc

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	DATADIR=${DESTDIR}${PREFIX}/share/elvis
INSTALL_MAKE_FLAGS+=	DOCDIR=${DESTDIR}${PREFIX}/share/doc/elvis

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
