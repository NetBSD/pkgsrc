# $NetBSD: Makefile,v 1.9 1999/04/01 14:07:56 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/12 02:19:40 obrien Exp
#

DISTNAME=		sam
PKGNAME=		sam-4.3
CATEGORIES=		plan9
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=		.msg.gz

MAINTAINER=		packages@netbsd.org

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

OPSYS!=			uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=		yes
.endif

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
