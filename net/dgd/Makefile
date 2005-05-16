# $NetBSD: Makefile,v 1.8 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	dgd-1.2p4
PKGNAME=	dgd-1.2.0.4
CATEGORIES=	net games
MASTER_SITES=	ftp://ftp.dworkin.nl/pub/dgd/

MAINTAINER=     sco@openface.ca
HOMEPAGE=	http://www.dworkin.nl/dgd/
COMMENT=	Object-oriented programmable server

LICENSE=	fee-based-commercial-use

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/dgd/src

PKGSRC_USE_TOOLS+=	gtar

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths and command names."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../mud.dgd
SUBST_SED.paths=	-e 's,/home/dworkin/,${PREFIX}/libdata/,g'

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/libexec/dgd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dgd
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dgd
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/dgd/tmp
	cd ${WRKDIR}/dgd && \
	${INSTALL_DATA} Copyright Credits README ${PREFIX}/share/doc/dgd
	${GTAR} cCf ${WRKDIR}/dgd/doc - . | ${GTAR} xCf \
		${PREFIX}/share/doc/dgd -
	${GTAR} cCf ${WRKDIR}/dgd - mud | ${GTAR} xCf ${PREFIX}/libdata/dgd -
	${CHOWN} -R ${BINOWN}:${BINGRP}  ${PREFIX}/libdata/dgd \
		${PREFIX}/share/doc/dgd
	${INSTALL_DATA} ${WRKSRC}/../mud.dgd ${PREFIX}/share/examples/dgd

.include "../../mk/bsd.pkg.mk"
