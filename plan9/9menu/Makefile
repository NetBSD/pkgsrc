# $NetBSD: Makefile,v 1.8 1999/02/04 18:54:35 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/08 12:23:55 tg Exp
#

DISTNAME=		9menu-1.5
CATEGORIES=		plan9
MASTER_SITES=		ftp://ftp.mathcs.emory.edu/pub/arnold/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		packages@netbsd.org

OPSYS!=			uname -s

.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=		yes
.endif

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
