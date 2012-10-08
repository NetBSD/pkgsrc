# $NetBSD: Makefile,v 1.13 2012/10/08 09:57:40 asau Exp $
#

DISTNAME=	visual_regexp-3.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://laurent.riesterer.free.fr/regexp/
COMMENT=	Easily design and debug regular expressions graphically

NO_BUILD=	yes
USE_TOOLS+=	wish:run

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	Fixing a hardcoded command.
SUBST_STAGE.wish=	pre-configure
SUBST_FILES.wish=	visual_regexp.tcl
SUBST_SED.wish=		-e 's,wish8.3,${WISH},g'

SUBST_CLASSES+=		command
SUBST_MESSAGE.command=	Fixing command names.
SUBST_STAGE.command=	pre-configure
SUBST_FILES.command=	visual_regexp.tcl
SUBST_SED.command=	-e 's,tkregexp,visual_regexp,g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp.tcl \
	    ${DESTDIR}${PREFIX}/bin/visual_regexp

.include "../../mk/bsd.pkg.mk"
