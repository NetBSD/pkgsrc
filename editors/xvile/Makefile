# $NetBSD: Makefile,v 1.17 1999/03/08 10:53:56 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp
#

DISTNAME=	vile-8.2
PKGNAME=	xvile-8.2
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+= --with-screen=${SCREEN_TYPE}
INSTALL_TARGET=	install install-perl

.include "../../mk/bsd.prefs.mk"

pre-configure:
	@${ECHO} "To use xvile with menus, set the variable USE_MENUS"
	@${ECHO} "in the environment or in /etc/mk.conf"

.if defined(USE_MENUS)
SCREEN_TYPE=	Xaw
.else
SCREEN_TYPE=	x11
.endif

post-install:
	@${ECHO} "You might want to copy the *.rc files from the source tree before"
	@${ECHO} "doing \`${MAKE} clean'."
.if defined(USE_MENUS)
	@${ECHO} "And also take a look at README.MENU !"
.endif

.include "../../mk/bsd.pkg.mk"
