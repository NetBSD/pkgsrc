# New ports collection makefile for:    rtty
# Version required:     3.2
# Date created:         24 Aug 1996
# Whom:                 jkh
#
# Author:		Paul Vixie / Internet Software Consortium
#
# $NetBSD: Makefile,v 1.4 1998/01/24 23:33:13 hubertf Exp $
# FreeBSD Id: Makefile,v 1.3 1997/01/06 12:13:36 jkh Exp
#

DISTNAME=       rtty-3.2
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.vix.com/pub/vixie/

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=   yes

OPSYS!=		uname -s

.if (${OPSYS} == "NetBSD")
pre-configure:
	for f in `find ${WRKDIR} -type f -print|xargs ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
.endif

.include <bsd.port.mk>
