# $NetBSD: Makefile,v 1.22 2004/06/18 02:22:01 minskim Exp $

DISTNAME=		xconq-7.4.1
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/
PKGREVISION=		2

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://sources.redhat.com/xconq/
COMMENT=		Xconq is a general strategy game system

USE_BUILDLINK3=		YES
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

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
