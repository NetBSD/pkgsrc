# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:36 agc Exp $
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

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
