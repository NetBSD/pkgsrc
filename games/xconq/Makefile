# $NetBSD: Makefile,v 1.9 2001/06/25 22:52:25 zuntum Exp $

DISTNAME=		xconq-7.4.1
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://sources.redhat.com/xconq/
COMMENT=		Xconq is a general strategy game system

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-alternate-scoresdir=/var/games/xconq/scores	\
			--with-tclconfig="${BUILDLINK_DIR}/lib"			\
			--with-tkconfig="${BUILDLINK_DIR}/lib"

MAKE_ENV+=		LOCALBASE="${LOCALBASE}"

INFO_FILES=     	hacking.info xcdesign.info xconq.info

post-build:
	cd ${WRKSRC}/doc && ${GMAKE} info

post-install:
	cd ${WRKSRC}/doc && ${GMAKE} install-info

.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
