# $NetBSD: Makefile,v 1.1.1.1 2002/09/02 10:10:03 agc Exp $
#

DISTNAME=	visual_regexp-3.0
CATEGORIES=	misc
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://laurent.riesterer.free.fr/regexp/
COMMENT=	Easily design and debug regular expressions graphically

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp.tcl \
	    ${PREFIX}/bin/visual_regexp

.include "../../mk/bsd.pkg.mk"
