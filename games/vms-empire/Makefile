# $NetBSD: Makefile,v 1.16 2016/01/11 19:37:43 leot Exp $
#

DISTNAME=	vms-empire-1.14
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-patch
SUBST_MESSAGE.makefile=	Fixing hardcoded paths
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
