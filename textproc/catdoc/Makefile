# $NetBSD: Makefile,v 1.2 1998/06/20 21:39:58 tron Exp $
#

DISTNAME=	catdoc-0.35
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	frueauf@netbsd.org

DEPENDS=	tk-8.0p2:../../x11/tk80

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/wordview \
		> ${PREFIX}/bin/wordview
	chmod 755 ${PREFIX}/bin/wordview

.include "../../mk/bsd.pkg.mk"
