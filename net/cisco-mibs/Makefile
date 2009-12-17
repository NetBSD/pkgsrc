# $NetBSD: Makefile,v 1.6 2009/12/17 22:22:05 abs Exp $

DISTNAME=	cisco-mibs-20050210
PKGREVISION=	1
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
COMMENT=	Public SNMPv1 and SNMPv2 MIBs from Cisco

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

USE_TOOLS+=	gtar

MIBDIR=		${PREFIX}/share/cisco-mibs

INSTALLATION_DIRS+=	share/cisco-mibs
PKG_DESTDIR_SUPPORT=	user-destdir
do-install:

.for distfile in ${DISTFILES}
	@${ECHO_MSG} -n "Extracting ${distfile} ... "
	${GTAR} -xz \
	    --exclude=v1-readme \
	    --exclude=v2-readme \
	    -C ${DESTDIR}${MIBDIR} -f ${DISTDIR}/${DIST_SUBDIR}/${distfile}
	@${ECHO_MSG} "done"
.endfor
	@${ECHO_MSG} -n "Fixing file ownerships ... "
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${MIBDIR}
	@${ECHO_MSG} "done"

.include "../../mk/bsd.pkg.mk"
