# $NetBSD: Makefile,v 1.15 2001/06/21 17:02:23 fredb Exp $
# FreeBSD Id: Makefile,v 1.25 1998/07/16 06:44:37 vanilla Exp
#

DISTNAME=	mgetty1.1.26-Apr16
PKGNAME=	mgetty-1.1.26
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/ \
		ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alpha.greenie.net/mgetty/
COMMENT=	Handle external logins, send and receive faxes

DEPENDS=	netpbm-[0-9]*:../../graphics/netpbm

CONFLICTS=	hylafax-*

WRKSRC=		${WRKDIR}/${PKGNAME}
INFO_FILES=	mgetty.info
INSTALL_FILE=	${WRKDIR}/INSTALL

MGETTY_CONFDIR=	${PREFIX}/etc/mgetty+sendfax
#MGETTY_CONFDIR=/etc/mgetty
MAKE_ENV+=	MGETTY_CONFDIR=${MGETTY_CONFDIR}

post-configure:
	${SED} -e 's#$${INSTALL_DATA_DIR}#${INSTALL_DATA_DIR}#' \
		-e 's#$${MGETTY_CONFDIR}#${MGETTY_CONFDIR}#' \
		-e 's#$${PAX}#${PAX}#' \
		-e 's#$${PREFIX}#${PREFIX}#' \
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	cd ${WRKSRC}; \
	    ${MV} faxrunq.config faxrunq.config.old; \
	    ${SED} 's#/usr/local#${PREFIX}#' \
		    faxrunq.config.old > faxrunq.config

post-install:
	${INSTALL_DATA_DIR} ${MGETTY_CONFDIR}
	cd ${PREFIX}/share/examples/mgetty+sendfax; \
	    ${PAX} -r -w -pe -k * ${MGETTY_CONFDIR}

.include "../../mk/bsd.pkg.mk"
