# $NetBSD: Makefile,v 1.3 2000/08/31 07:26:23 kleink Exp $

DISTNAME=		xconq-7.3.3
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://sources.redhat.com/xconq/

DEPENDS+=		tcl-8.0.5:../../lang/tcl80
DEPENDS+=		tk-8.0.5:../../x11/tk80

USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-tclconfig=${LOCALBASE}/lib/tcl8.0 \
			--with-tkconfig=${LOCALBASE}/lib/tk8.0 \
			--enable-alternate-scoresdir=/var/games/xconq/scores

INFO_FILES=     	hacking.info xcdesign.info xconq.info

post-build:
	cd ${WRKSRC}/doc && ${GMAKE} info

post-install:
	cd ${WRKSRC}/doc && ${GMAKE} install-info

.include "../../mk/bsd.pkg.mk"
