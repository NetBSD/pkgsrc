# $NetBSD: Makefile,v 1.7 1998/05/06 09:03:50 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp
#

DISTNAME=	vile
PKGNAME=	xvile-7.3
WRKSRC=		${WRKDIR}/vile-7.3
CATEGORIES=	editors
# agc - vile-7.4 is on the MASTER_SITES now, so grab the 7.3 distfile
#	from ftp.netbsd.org. We'll do a 7.4 package ASAP, when circumstances
#	permit.
# MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
#		ftp://id.wing.net/pub/pgf/vile/
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-screen=${SCREEN_TYPE}
MAN1=		xvile.1

pre-configure:
	@echo "To use xvile with menus, set the environment variable USE_MENUS"

.if defined(USE_MENUS)
SCREEN_TYPE=	Xaw
.else
SCREEN_TYPE=	x11
.endif

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`make clean'."
.if defined(USE_MENUS)
	@echo "And also take a look at README.MENU !"
.endif

.include "../../mk/bsd.pkg.mk"
