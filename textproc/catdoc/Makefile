# $NetBSD: Makefile,v 1.3 1998/06/22 09:10:24 agc Exp $
#

DISTNAME=	catdoc-0.35
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	frueauf@netbsd.org

DEPENDS=	tk-8.0p2:../../x11/tk80

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/wordview \
		> ${PREFIX}/bin/wordview
	chmod 755 ${PREFIX}/bin/wordview

.include "../../mk/bsd.pkg.mk"
