# $NetBSD: Makefile,v 1.1.1.1 2000/12/14 00:54:49 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/08 12:23:55 tg Exp
#

DISTNAME=		9menu-1.5
CATEGORIES=		plan9 misc
MASTER_SITES=		ftp://ftp.mathcs.emory.edu/pub/arnold/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		packages@netbsd.org

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=		yes
.endif

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
