# $NetBSD: Makefile,v 1.9 2001/02/16 15:11:03 wiz Exp $
# FreeBSD Id: Makefile,v 1.3 1996/12/08 01:11:27 max Exp
#

DISTNAME=	xmahjongg
PKGNAME=	xmahjongg-1.0
CATEGORIES=	games
# Most Usenet archive sites don't store it as a .tar.gz, but Slackware
# and its mirrors do.
MASTER_SITES=	ftp://wcarchive.cdrom.com/pub/linux/slackware/source/xap/xgames/

MAINTAINER=	packages@netbsd.org
COMMENT=	The Chinese game of Mahjongg for X11

WRKSRC=		${WRKDIR}/xmahjongg
USE_IMAKE=	yes

RESTRICTED=	"Restrictive copyright"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

post-extract:
	@${CP} ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

post-install:
	${X11BASE}/bin/mkfontdir ${X11PREFIX}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
