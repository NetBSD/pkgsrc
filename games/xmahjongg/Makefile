# $NetBSD: Makefile,v 1.3 1998/04/20 11:56:23 frueauf Exp $
# FreeBSD Id: Makefile,v 1.3 1996/12/08 01:11:27 max Exp
#

DISTNAME=	xmahjongg
PKGNAME=	xmahjongg-1.0
CATEGORIES=	games
# Most Usenet archive sites don't store it as a .tar.gz, but Slackware
# and it's mirrors do.
MASTER_SITES=	ftp://wcarchive.cdrom.com/pub/linux/slackware/source/xap/xgames/

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/xmahjongg
USE_IMAKE=	yes

NO_CDROM=	"Restrictive copyright"

CAT6=		xmahjongg.0

post-extract:
	@${CP} ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

.include <../../mk/bsd.pkg.mk>
