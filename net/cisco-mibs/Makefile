# $NetBSD: Makefile,v 1.10 2020/01/05 18:45:58 kim Exp $

DISTNAME=	cisco-mibs-20170101
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cisco.com/pub/mibs/v1/
MASTER_SITES+=	ftp://ftp.cisco.com/pub/mibs/v2/
DISTFILES=	v1.tar.gz \
		v2.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Public SNMPv1 and SNMPv2 MIBs from Cisco

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

USE_TOOLS+=	gtar gzip

MIBDIR=		${PREFIX}/share/cisco-mibs

INSTALLATION_DIRS+=	share/cisco-mibs

do-install:

.for distfile in ${DISTFILES}
	@${ECHO_MSG} -n "Extracting ${distfile} ... "
	${GTAR} -xz \
	    --strip-components=3 \
	    --exclude=v1-readme \
	    --exclude=v2-readme \
	    -C ${DESTDIR}${MIBDIR} -f ${DISTDIR}/${DIST_SUBDIR}/${distfile}
	@${ECHO_MSG} "done"
.endfor
	@${ECHO_MSG} -n "Fixing file ownerships ... "
	${CHOWN} -R ${BINOWN}:${BINGRP} ${DESTDIR}${MIBDIR}
	@${ECHO_MSG} "done"

.include "../../mk/bsd.pkg.mk"
