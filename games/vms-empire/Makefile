# $NetBSD: Makefile,v 1.19 2026/03/24 12:46:06 wiz Exp $

DISTNAME=	vms-empire-1.19
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing hardcoded paths
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
