# $NetBSD: Makefile,v 1.33.2.1 2007/05/15 22:19:52 salo Exp $

DISTNAME=		xconq-7.4.1
PKGREVISION=		6
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://sources.redhat.com/xconq/
COMMENT=		Xconq is a general strategy game system

USE_X11BASE=		YES
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-alternate-scoresdir=${VARBASE}/games/xconq/scores
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ARGS+=	--with-tkconfig="${BUILDLINK_PREFIX.tk}/lib"

MAKE_ENV+=		LOCALBASE=${LOCALBASE:Q}
MAKE_FLAGS+=		mandir=${PREFIX:Q}/${PKGMANDIR:Q}		\
			infodir=${PREFIX:Q}/${PKGINFODIR:Q}
INFO_FILES=	# PLIST

post-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} info

post-install:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} install-info

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
