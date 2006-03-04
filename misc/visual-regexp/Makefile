# $NetBSD: Makefile,v 1.9 2006/03/04 21:30:13 jlam Exp $
#

DISTNAME=	visual_regexp-3.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://laurent.riesterer.free.fr/regexp/
COMMENT=	Easily design and debug regular expressions graphically

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp.tcl \
	    ${PREFIX}/bin/visual_regexp

.include "../../mk/bsd.pkg.mk"
