# $NetBSD: Makefile,v 1.9 2004/03/04 02:57:00 simonb Exp $
#

DISTNAME=	priv-1.0-beta2
PKGNAME=	priv-1.0beta2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.thistledown.com.au/pub/simonb/

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
