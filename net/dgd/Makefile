# $NetBSD: Makefile,v 1.21 2020/03/30 19:39:05 joerg Exp $

DISTNAME=	dgd-1.2p4
PKGNAME=	dgd-1.2.0.4
PKGREVISION=	1
CATEGORIES=	net games
MASTER_SITES=	# ftp://ftp.dworkin.nl/pub/dgd/

MAINTAINER=	sco@openface.ca
HOMEPAGE=	http://www.dworkin.nl/dgd/
COMMENT=	Object-oriented programmable server
LICENSE=	fee-based-commercial-use

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	tar

WRKSRC=			${WRKDIR}/dgd
BUILD_DIRS=		src

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths and command names.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mud.dgd
SUBST_SED.paths=	-e 's,/home/dworkin/,${PREFIX}/libdata/,g'

INSTALLATION_DIRS=	libexec share/doc/dgd share/examples/dgd libdata/dgd/tmp
PKG_DESTDIR_SUPPORT=	destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/a.out ${DESTDIR}${PREFIX}/libexec/dgd
	cd ${WRKDIR}/dgd && \
	${INSTALL_DATA} Copyright Credits README ${DESTDIR}${PREFIX}/share/doc/dgd
	${TAR} -cf - -C ${WRKDIR}/dgd/doc . | \
	    ${TAR} -xf - -C ${DESTDIR}${PREFIX}/share/doc/dgd
	${TAR} -cf - -C ${WRKDIR}/dgd mud | \
	    ${TAR} -xf - -C ${DESTDIR}${PREFIX}/libdata/dgd
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${PREFIX}/libdata/dgd \
		${DESTDIR}${PREFIX}/share/doc/dgd
	${INSTALL_DATA} ${WRKSRC}/mud.dgd ${DESTDIR}${PREFIX}/share/examples/dgd

.include "../../mk/bsd.pkg.mk"
