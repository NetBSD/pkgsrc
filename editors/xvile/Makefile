# $NetBSD: Makefile,v 1.6 1998/04/20 11:56:23 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp
#

DISTNAME=	vile
PKGNAME=	xvile-7.3
WRKSRC=		${WRKDIR}/vile-7.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/

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
