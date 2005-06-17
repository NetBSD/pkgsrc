# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:23 jlam Exp $
#

DISTNAME=	visual_regexp-3.0
CATEGORIES=	misc
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://laurent.riesterer.free.fr/regexp/
COMMENT=	Easily design and debug regular expressions graphically

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp.tcl \
	    ${PREFIX}/bin/visual_regexp

.include "../../mk/bsd.pkg.mk"
