# $NetBSD: Makefile,v 1.3 2003/07/17 21:50:02 grant Exp $
#

DISTNAME=	visual_regexp-3.0
CATEGORIES=	misc
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://laurent.riesterer.free.fr/regexp/
COMMENT=	Easily design and debug regular expressions graphically

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp.tcl \
	    ${PREFIX}/bin/visual_regexp

.include "../../mk/bsd.pkg.mk"
