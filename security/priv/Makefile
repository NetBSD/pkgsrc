# $NetBSD: Makefile,v 1.6 2001/02/17 17:50:03 wiz Exp $
#

DISTNAME=	priv-1.0-beta
PKGNAME=	priv-1.0beta
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	simonb@netbsd.org
COMMENT=	execute commands as a different user

GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/plist

.include "../../mk/bsd.prefs.mk"

PRIV_CONF_DIR?=	${LOCALBASE}/etc

CONFIGURE_ARGS+=	--sysconfdir=${PRIV_CONF_DIR}

post-install:
	${SED} -e 's|@PRIV_CONF_DIR@|${PRIV_CONF_DIR}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
