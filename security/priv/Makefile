# $NetBSD: Makefile,v 1.8 2003/07/21 17:20:29 martti Exp $
#

DISTNAME=	priv-1.0-beta
PKGNAME=	priv-1.0beta
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Execute commands as a different user

GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/plist

.include "../../mk/bsd.prefs.mk"

PRIV_CONF_DIR?=	${LOCALBASE}/etc

CONFIGURE_ARGS+=	--sysconfdir=${PRIV_CONF_DIR}

post-install:
	${SED} -e 's|@PRIV_CONF_DIR@|${PRIV_CONF_DIR}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
