# $NetBSD: Makefile,v 1.2 1998/04/15 22:03:38 tron Exp $
# $FreeBSD Id: Makefile,v 1.3 1996/12/08 01:11:27 max Exp
#

DISTNAME=	xmahjongg
PKGNAME=	xmahjongg-1.0
CATEGORIES=	games
# Most Usenet archive sites don't store it as a .tar.gz, but Slackware
# and it's mirrors do.
MASTER_SITES=	ftp://wcarchive.cdrom.com/pub/linux/slackware/source/xap/xgames/

MAINTAINER=	joerg@freebsd.org

WRKSRC=		${WRKDIR}/xmahjongg
USE_IMAKE=	yes

NO_CDROM=	"Restrictive copyright"

CAT6=	xmahjongg.0

post-extract:
	@${CP} ${WRKSRC}/xmahjongg.6 ${WRKSRC}/xmahjongg.man

.include <../../mk/bsd.pkg.mk>
