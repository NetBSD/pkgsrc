# $NetBSD: Makefile,v 1.18 2008/06/20 01:09:31 joerg Exp $
#

DISTNAME=		gopher_3.0.11
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://quux.org/devel/gopher/Downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		gopher://quux.org/1/devel/gopher/
COMMENT=		Distributed document delivery client

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/gopher
PKG_SYSCONFSUBDIR?=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/gopher
MAKE_ENV+=		EGDIR=${EGDIR:Q}

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--disable-auth
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CONF_FILES+=		${EGDIR}/gopher.hlp ${PKG_SYSCONFDIR}/gopher.hlp
CONF_FILES+=		${EGDIR}/gopher.rc ${PKG_SYSCONFDIR}/gopher.rc
CONF_FILES+=		${EGDIR}/gopherremote.rc ${PKG_SYSCONFDIR}/gopherremote.rc

.include "../../mk/bsd.pkg.mk"
