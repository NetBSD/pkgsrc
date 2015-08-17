# $NetBSD: Makefile,v 1.8 2015/08/17 17:11:21 wiz Exp $
#

DISTNAME=	mg-20110905
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://homepage.boetes.org/software/mg/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://homepage.boetes.org/software/mg/
COMMENT=	Small, fast, public domain EMACS style editor

HAS_CONFIGURE=	yes
USE_NCURSES=	yes # Uses NCURSES internals
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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
