# $NetBSD: Makefile,v 1.9 1999/10/21 16:54:00 agc Exp $
#

DISTNAME=	catdoc-0.91.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.0.5:../../x11/tk80

WRKSRC=		${WRKDIR}/catdoc

USE_X11=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-Dunix

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MANCOMPRESSED_IF_MANZ=	yes
PLIST_SRC=	${WRKDIR}/PLIST-src

post-install:
	${CP} ${FILESDIR}/PLIST ${PLIST_SRC}
	${ECHO} "man/cat1/catdoc.0" >> ${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
