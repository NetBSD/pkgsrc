# $NetBSD: Makefile,v 1.3 2000/07/14 12:39:30 agc Exp $
#

DISTNAME=	priv-1.0-beta
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	simonb@netbsd.org
#HOMEPAGE=	

GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/plist

.include "../../mk/bsd.prefs.mk"

PRIV_CONF_DIR?=	${LOCALBASE}/etc

CONFIGURE_ARGS+=	--sysconfdir=${PRIV_CONF_DIR}

post-install:
	${SED} -e 's|@PRIV_CONF_DIR@|${PRIV_CONF_DIR}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
