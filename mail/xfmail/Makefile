# $NetBSD: Makefile,v 1.3 1998/08/20 15:17:10 tsarna Exp $
#

DISTNAME=       xfmail-1.3
CATEGORIES=     mail x11
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://Burka.NetVision.net.il/xfmail/xfmail.html

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=       xforms-0.88:../../x11/xforms

ONLY_FOR_ARCHS=	arm32 i386 m68k sparc pc532

RESTRICTED=	"Selling this software requires permission of the authors."

USE_X11=	YES
GNU_CONFIGURE=	YES

post-install:
	${MKDIR} ${PREFIX}/share/doc/xfmail
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xfmail

.include "../../mk/bsd.pkg.mk"
