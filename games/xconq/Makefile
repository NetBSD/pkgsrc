# $NetBSD: Makefile,v 1.19 2004/01/24 13:30:57 grant Exp $

DISTNAME=		xconq-7.4.1
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/
PKGREVISION=		1

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://sources.redhat.com/xconq/
COMMENT=		Xconq is a general strategy game system

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-alternate-scoresdir=/var/games/xconq/scores
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ARGS+=	--with-tkconfig="${BUILDLINK_PREFIX.tk}/lib"

MAKE_ENV+=		LOCALBASE="${LOCALBASE}"

USE_MAKEINFO=		YES
INFO_FILES=     	hacking.info xcdesign.info xconq.info

post-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} info

post-install:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-info

.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
