# $NetBSD: Makefile,v 1.7 2000/07/11 11:01:06 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1996/12/08 01:11:27 max Exp
#

DISTNAME=	xmahjongg
PKGNAME=	xmahjongg-1.0
CATEGORIES=	games
# Most Usenet archive sites don't store it as a .tar.gz, but Slackware
# and its mirrors do.
MASTER_SITES=	ftp://wcarchive.cdrom.com/pub/linux/slackware/source/xap/xgames/

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/xmahjongg
USE_IMAKE=	yes

NO_CDROM=	"Restrictive copyright"

post-extract:
	@${CP} ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

post-install:
	${X11BASE}/bin/mkfontdir ${X11PREFIX}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
