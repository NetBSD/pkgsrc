# $NetBSD: Makefile,v 1.5 1998/10/20 22:28:44 hubertf Exp $
#

DISTNAME=	catdoc-0.35
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.0p2:../../x11/tk80

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

CFLAGS+=	-Dunix

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/wordview \
		> ${PREFIX}/bin/wordview
	chmod 755 ${PREFIX}/bin/wordview

.include "../../mk/bsd.pkg.mk"
