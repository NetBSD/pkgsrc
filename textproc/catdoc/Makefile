# $NetBSD: Makefile,v 1.7 1999/04/26 19:25:06 garbled Exp $
#

DISTNAME=	catdoc-0.35
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.0.5:../../x11/tk80

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

USE_X11=	yes
CFLAGS+=	-Dunix

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/wordview \
		> ${PREFIX}/bin/wordview
	chmod 755 ${PREFIX}/bin/wordview

.include "../../mk/bsd.pkg.mk"
