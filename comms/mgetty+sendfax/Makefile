# $NetBSD: Makefile,v 1.19 2002/02/18 15:14:04 seb Exp $
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

CONFLICTS=	hylafax-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME}
INFO_FILES=	mgetty.info
INSTALL_FILE=	${WRKDIR}/INSTALL

MGETTY_CONFDIR=	${PREFIX}/etc/mgetty+sendfax
#MGETTY_CONFDIR=/etc/mgetty
MAKE_ENV+=	MGETTY_CONFDIR=${MGETTY_CONFDIR}

USE_BUILDLINK_ONLY=	# defined

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

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

.include "../../graphics/netpbm/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
