# $NetBSD: Makefile,v 1.4 2000/09/09 01:53:03 wiz Exp $

DISTNAME=		xconq-7.3.3
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://sources.redhat.com/xconq/

DEPENDS+=		tcl-8.3.2:../../lang/tcl
DEPENDS+=		tk-8.3.2:../../x11/tk

USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-tclconfig=${LOCALBASE}/lib \
			--with-tkconfig=${LOCALBASE}/lib \
			--enable-alternate-scoresdir=/var/games/xconq/scores
MAKE_ENV+=		LOCALBASE="${LOCALBASE}"

INFO_FILES=     	hacking.info xcdesign.info xconq.info

post-build:
	cd ${WRKSRC}/doc && ${GMAKE} info

post-install:
	cd ${WRKSRC}/doc && ${GMAKE} install-info

.include "../../mk/bsd.pkg.mk"
