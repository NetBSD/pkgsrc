# $NetBSD: Makefile,v 1.8 1999/07/02 08:37:29 agc Exp $
#

DISTNAME=	catdoc-0.35
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.0.5:../../x11/tk80

MANCOMPRESSED_IF_MANZ=	yes

USE_X11=	yes
CFLAGS+=	-Dunix

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/wordview \
		> ${PREFIX}/bin/wordview
	chmod 755 ${PREFIX}/bin/wordview

.include "../../mk/bsd.pkg.mk"
