# $NetBSD: Makefile,v 1.2 2005/05/16 01:15:32 jlam Exp $

DISTNAME=	cisco-mibs-20050210
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gw.com/pub/mibs/${DISTNAME}/
DISTFILES=	v1.tar.gz \
		v2.tar.gz

#
# Files are tarred up every day at
# ftp://ftp.cisco.com/pub/mibs/v1/
# ftp://ftp.cisco.com/pub/mibs/v2/
#

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Public SNMPv1 and SNMPv2 MIBs from Cisco.

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

PKGSRC_USE_TOOLS+=	gtar

MIBDIR=		${PREFIX}/share/cisco-mibs

do-install:
	${INSTALL_DATA_DIR} ${MIBDIR}
.for DISTFILE in ${DISTFILES}
	@${ECHO_MSG} -n "Extracting ${DISTFILE} ... "
	@${GTAR} -xz \
	    --exclude=v1-readme \
	    --exclude=v2-readme \
	    -C ${MIBDIR} -f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE}
	@${ECHO_MSG} "done"
.endfor
	@${ECHO_MSG} -n "Fixing file ownerships ... "
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${MIBDIR}
	@${ECHO_MSG} "done"

.include "../../mk/bsd.pkg.mk"
