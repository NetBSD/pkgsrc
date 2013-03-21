# $NetBSD: Makefile,v 1.1 2013/03/21 00:11:06 mspo Exp $
#

DISTNAME=	sandy-0.4
CATEGORIES=	editors
MASTER_SITES=	http://git.suckless.org/sandy/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tools.suckless.org/sandy
COMMENT=	Sandy is an ncurses text editor
LICENSE=	mit

SUBST_CLASSES=	fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=	config.mk
SUBST_SED.fix-paths=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=	-e 's,/usr/include,${BUILDLINK_PREFIX.ncursesw}/include,g'
SUBST_SED.fix-paths+=	-e 's,/usr/lib,${BUILDLINK_PREFIX.ncursesw}/lib -Wl\,-R${BUILDLINK_PREFIX.ncursesw}/lib,g'
SUBST_SED.fix-paths+=	-e 's,share/man,man,g'

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
