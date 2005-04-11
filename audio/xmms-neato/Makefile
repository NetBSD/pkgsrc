# $NetBSD: Makefile,v 1.16 2005/04/11 21:44:59 tv Exp $
#

DISTNAME=	neato
PKGNAME=	xmms-neato-20010818
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.rpi.edu/~mullr/xmms/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rpi.edu/~mullr/xmms/
COMMENT=	Circle effect XMMS plugin

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes

GNU_CONFIGURE=	YES

post-extract:
	cd ${WRKSRC} ; \
	${RM} mkinstalldirs ; \
	${ECHO} "#!/bin/sh" >>mkinstalldirs ; \
	${ECHO} 'exec ${MKDIR} "$$@"' >>mkinstalldirs ; \
	${CHMOD} +x mkinstalldirs ; \
	${RM} install-sh ; \
	${ECHO} "#!/bin/sh" >>install-sh ; \
	${ECHO} 'exec ${INSTALL} "$$@"' >>install-sh ; \
	${CHMOD} +x install-sh ; \
	${MAKE} distclean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
