# $NetBSD: Makefile,v 1.10 2017/01/04 11:18:44 roy Exp $
#

DISTNAME=	mg-20110905
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://homepage.boetes.org/software/mg/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://homepage.boetes.org/software/mg/
COMMENT=	Small, fast, public domain EMACS style editor

HAS_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_TOOLS+=	install
MAKE_ENV+=	prefix=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFLICTS+=	mg2a-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile.in mg.1
SUBST_SED.path=		-e "s|/usr/local|${PREFIX}/|g"
SUBST_SED.path+=	-e "s|/usr/share/doc|${PREFIX}/share/doc|g"
SUBST_SED.path+=	-e "s|/usr/bin/install|${INSTALL}|g"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
