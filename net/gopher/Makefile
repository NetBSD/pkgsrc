# $NetBSD: Makefile,v 1.23 2015/08/18 07:31:15 wiz Exp $
#

DISTNAME=		gopher_3.0.11
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://gopher.quux.org:70/devel/gopher/Downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		gopher://quux.org/1/devel/gopher/
COMMENT=		Distributed document delivery client

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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
