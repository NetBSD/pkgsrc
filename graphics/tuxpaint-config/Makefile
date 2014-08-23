# $NetBSD: Makefile,v 1.18 2014/08/23 21:40:46 wiz Exp $

DISTNAME=		tuxpaint-config-0.0.13
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tuxpaint.org/
COMMENT=		Configuration program for tuxpaint
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake msgfmt

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-install:
	${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint-config -name CVS -exec ${RM} -r {} \; 2>/dev/null || ${TRUE}
	${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint-config -name .xvpics -exec ${RM} -r {} \; 2>/dev/null || ${TRUE}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
