# $NetBSD: Makefile,v 1.6 1998/04/20 11:56:31 frueauf Exp $
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

MAN1=			9menu.1

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

.include "../../mk/bsd.pkg.mk"
