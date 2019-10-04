# $NetBSD: Makefile,v 1.24 2019/10/04 09:34:41 leot Exp $
#

DISTNAME=		gopher_3.0.17
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		net
MASTER_SITES=		http://gopher.quux.org:70/devel/gopher/Downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		gopher://quux.org/1/devel/gopher/
COMMENT=		Distributed document delivery client
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/gopher-release-${PKGVERSION_NOREV}
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
