# $NetBSD: Makefile,v 1.13 2005/12/05 23:55:13 rillig Exp $
#

DISTNAME=		gopher_3.0.11
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		net
MASTER_SITES=		http://quux.org/devel/gopher/Downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		gopher://quux.org/1/devel/gopher/
COMMENT=		Distributed document delivery client and server

WRKSRC=			${WRKDIR}/gopher
PKG_SYSCONFSUBDIR?=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/gopher
MAKE_ENV+=		EGDIR=${EGDIR:Q}

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--disable-auth
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CONF_FILES+=		${EGDIR}/gopher.hlp ${PKG_SYSCONFDIR}/gopher.hlp
CONF_FILES+=		${EGDIR}/gopher.rc ${PKG_SYSCONFDIR}/gopher.rc
CONF_FILES+=		${EGDIR}/gopherremote.rc ${PKG_SYSCONFDIR}/gopherremote.rc

.include "../../mk/bsd.pkg.mk"
