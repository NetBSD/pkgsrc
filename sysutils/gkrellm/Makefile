# $NetBSD: Makefile,v 1.12 2001/11/01 14:08:00 hubertf Exp $
#

DISTNAME=	gkrellm-1.2.3
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=	yes

ALL_TARGET=	netbsd
INSTALL_TARGET=	install_netbsd
PLIST_SUBST+=	MKDIR='${MKDIR}' \
		RMDIR='${RMDIR}'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm/themes

.include "../../devel/pth/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
