# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:09 tv Exp $
#

DISTNAME=		tuxpaint-config-0.0.5
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.sonic.net/pub/users/nbs/unix/x/tuxpaint/config/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		ftp://ftp.sonic.net/pub/users/nbs/unix/x/tuxpaint/config/
COMMENT=		Configuration program for tuxpaint

USE_GNU_TOOLS+=		make
USE_X11=		YES

post-install:
	-${FIND} ${PREFIX}/share/tuxpaint-config -name CVS -exec ${RM} -r {} \; 2>/dev/null
	-${FIND} ${PREFIX}/share/tuxpaint-config -name .xvpics -exec ${RM} -r {} \; 2>/dev/null
	${RMDIR} ${PREFIX}/share/tuxpaint-config/fonts

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
