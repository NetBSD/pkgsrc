# $NetBSD: Makefile,v 1.3 2001/02/17 18:08:49 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/09/08 12:23:55 tg Exp
#

DISTNAME=		9menu-1.5
CATEGORIES=		plan9 misc
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		packages@netbsd.org
COMMENT=		Simple menu patterened after plan9

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=		yes
.endif

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
