# $NetBSD: Makefile,v 1.1.1.1 2002/04/25 15:19:37 tron Exp $

DISTNAME=	dgd-1.2p1
PKGNAME=	dgd-1.2.0.1
CATEGORIES=	net games
MASTER_SITES=	ftp://ftp.dworkin.nl/pub/dgd/ \
		ftp://ftp.imaginary.com/pub/LPC/servers/DGD/

MAINTAINER=     sco@openface.ca
HOMEPAGE=	http://www.dworkin.nl/dgd/
COMMENT=	Object-oriented programmable server

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/dgd/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/libexec/dgd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dgd
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dgd
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/dgd/tmp
	cd ${WRKDIR}/dgd && \
	${INSTALL_DATA} Copyright Credits README ${PREFIX}/share/doc/dgd
	${GTAR} cCf ${WRKDIR}/dgd/doc - . | ${GTAR} xCf ${PREFIX}/share/doc/dgd -
	${GTAR} cCf ${WRKDIR}/dgd - mud | ${GTAR} xCf ${PREFIX}/libdata/dgd -
	${CHOWN} -R ${BINOWN}:${BINGRP}  ${PREFIX}/libdata/dgd \
	  ${PREFIX}/share/doc/dgd
	${SED} -e "s#@PREFIX@#${PREFIX}#" ${WRKSRC}/../mud.dgd > ${PREFIX}/share/examples/dgd/mud.dgd

.include "../../mk/bsd.pkg.mk"
