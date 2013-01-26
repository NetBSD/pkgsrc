# $NetBSD: Makefile,v 1.16 2013/01/26 21:38:01 adam Exp $
#

DISTNAME=		tuxpaint-config-0.0.8
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.billsgames.com/unix/x/tuxpaint/config/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.billsgames.com/unix/x/tuxpaint/config/
COMMENT=		Configuration program for tuxpaint

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-install:
	-${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint-config -name CVS -exec ${RM} -r {} \; 2>/dev/null
	-${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint-config -name .xvpics -exec ${RM} -r {} \; 2>/dev/null

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
