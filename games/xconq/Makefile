# $NetBSD: Makefile,v 1.8 2001/05/05 19:51:14 jlam Exp $

DISTNAME=		xconq-7.4.1
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://sources.redhat.com/xconq/
COMMENT=		Xconq is a general strategy game system

DEPENDS+=		tcl>=8.3.2:../../lang/tcl
DEPENDS+=		tk>=8.3.2:../../x11/tk

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
